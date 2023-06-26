"""
DESCRIÇÃO:
    Fazer um sistema de upload de arquivos via UDP. Um servidor UDP deverá receber as partes dos arquivos
    (1024 bytes), verificar ao final a integridade via um checksum (SHA-1) e armazenar o arquivo em uma pasta padrão.
    Sugestões: o servidor pode receber o nome e tamanho do arquivo como o primeiro pacote e o checksum como o último.
    Testar o servidor com arquivos textos e binários (ex: imagens, pdf) de tamanhos arbitrários (ex: 100 bytes, 4KiB,
    4MiB). O protocolo para a comunicação deve ser criado e especificado textualmente ou graficamente

    Datagrama:

    porta de origem: 2 bytes
    porta de destino: 2 bytes
    ordem do pacote: 1 byte                     (1, 2, 3, 4, ...)
    ultimo pacote: 1 byte                       (0 ou 1)
    checksum: 20 bytes                          (SHA-1)
    tipo de arquivo: 1 byte                     (0 = texto, 1 = binário)
    Tamanho do nome do arquivo: 1 byte
    Nome do arquivo: 255 bytes
    Tamanho do arquivo: 2 bytes
    dados: 1024 bytes

    tamanho maximo do datagrama: 2 + 2 + 1 + 1 + 20 + 1 + 255 + 1024 + 2 + 1 = 1309 bytes

    OBS. O checksum será enviado apenas no último pacote
    OSB. o arquivo pode ser TANTO texto quanto binário
    OBS. Montar o arquivo em ordem e verificar o checksum

AUTOR: Felipe Archanjo da Cunha Mendes

DATA: 07/04/2023
"""

import socket
import threading
import os
import hashlib

class ServerUDP:
    def __init__(self, host, port):
        self.host = host    # IP do servidor
        self.port = port    # Porta do servidor
        self.server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
        self.server.bind((self.host, self.port)) # Bind
        self.lock = threading.Lock() # Lock
        self.clients = [] # Lista de clientes

    def start(self):
        print(f"[LISTENING]: Servidor iniciado em {self.host}:{self.port}")
        while True:
            try:
                # Recebe um pacote na porta udp
                print("Aguardando pacote...")
                data, addr = self.server.recvfrom(1309) # Recebe pacote

                if addr not in [cliente['cliente'] for cliente in self.clients]:
                    print(f"Cliente {addr} esta fazendo upload de um arquivo")
                    self.lock.acquire()
                    self.clients.append({
                        'cliente': addr,
                        'chunks': []
                    })
                    self.lock.release()

                # Cria uma thread para o cliente
                threading.Thread(target=self.handle_client, args=(data, addr)).start()

            except socket.timeout:
                pass
    
    def handle_client(self, chunk, addr):
        #print(f"Recebendo pacote de {addr}")

        try:
            # Separa os dados
            port_origem = int.from_bytes(chunk[0:2], byteorder='big')
            port_destino = int.from_bytes(chunk[2:4], byteorder='big')
            ordem = int.from_bytes(chunk[4:5], byteorder='big')
            ultimo = int.from_bytes(chunk[5:6], byteorder='big')
            checksum = chunk[6:26]
            tipo = int.from_bytes(chunk[26:27], byteorder='big')
            tamanho_nome = int.from_bytes(chunk[27:28], byteorder='big')
            nome = chunk[28:28+tamanho_nome].decode('utf-8')
            tamanho_arquivo = int.from_bytes(chunk[28+255:30+255], byteorder='big')
            dados = chunk[30+255:30+255+tamanho_arquivo]

            print(f"Recebido pacote {ordem} de {addr}")

            # Se for arquivo texto, converte para string
            if tipo == 0:
                dados = dados.decode('utf-8')
                dados = dados.replace('\x00', '')
            
            # Se for o ultimo pacote, salva o checksum
            if ultimo == 1:
                checksum = checksum.hex()
            
            # Adiciona o chunk na lista de chunks do cliente
            self.lock.acquire()
            for cliente in self.clients:
                if cliente['cliente'] == addr:
                    cliente['chunks'].append({
                        'ordem': ordem,
                        'dados': dados
                    })
            self.lock.release()

            # Se for o ultimo pacote, monta o arquivo
            if ultimo == 1:
                #print(self.clients)

                # Ordena os chunks
                for cliente in self.clients:
                    if cliente['cliente'] == addr:
                        chunks = sorted(cliente['chunks'], key=lambda k: k['ordem'])
                        break

                # Concatena os chunks
                if tipo == 0:
                    arquivo = ''
                else:
                    arquivo = b''

                for chunk in chunks:
                    arquivo += chunk['dados']

                # imprime a ordem de todos os chunks
                #print(f"Ordem dos chunks: {[chunk['ordem'] for chunk in chunks]}")

                # Calcula o checksum
                if tipo == 0:
                    checksum_calculado = hashlib.sha1(arquivo.encode()).hexdigest()
                else:
                    checksum_calculado = hashlib.sha1(arquivo).hexdigest()

                # Verifica se o checksum é igual
                if checksum == checksum_calculado:
                    print(f"Checksum do arquivo {nome} é válido")
                else:
                    print(f"Checksum do arquivo {nome} é inválido... Provavelmente houve perda de pacotes")
                    #print(f"Checksum recebido: {checksum}")
                    #print(f"Checksum calculado: {checksum_calculado}")
                    exit()
                
                # Cria o diretorio 'uploads' se nao existir
                if not os.path.exists('uploads'):
                    os.makedirs('uploads')
                
                # Cria o arquivo de texto ou binario
                try:
                    if tipo == 0:
                        with open(f'uploads/{nome}', 'w') as f:
                            f.write(arquivo)
                    else:
                        with open(f'uploads/{nome}', 'wb') as f:
                            f.write(arquivo)
                except Exception as e:
                    print(f"Erro ao criar arquivo: {e}")
                    exit()
                
                # Remove o cliente da lista de clientes
                self.lock.acquire()
                for cliente in self.clients:
                    if cliente['cliente'] == addr:
                        self.clients.remove(cliente)
                        #print(f"Cliente {addr} removido da lista de clientes")
                self.lock.release()

                print(f"Arquivo {nome} salvo com sucesso")
            
            # Encerra a thread
            exit()

        except socket.timeout:
            print(f"Timeout do cliente {addr}")

    
    def response(self, tipo, nome, addr):
        """
        PACOTE:

        porta de origem: 2 bytes
        porta de destino: 2 bytes
        tipo de response: 1 byte                (0 = success, 1 = error)
        nome do arquivo: 255 bytes

        total: 260 bytes
        """

        # Cria o pacote
        port_origem = self.port.to_bytes(2, byteorder='big')
        port_destino = addr[1].to_bytes(2, byteorder='big')
        tipo = tipo.to_bytes(1, byteorder='big')
        nome = nome.encode('utf-8')
        nome = nome.ljust(255, b'\x00')

        # Monta o pacote
        pacote = port_origem + port_destino + tipo + nome

        # Envia o pacote
        self.server.sendto(pacote, addr)



if __name__ == "__main__":
    server = ServerUDP('localhost', 9999)
    server.start()








