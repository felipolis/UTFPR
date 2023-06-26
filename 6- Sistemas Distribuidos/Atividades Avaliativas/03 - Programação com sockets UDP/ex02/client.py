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
import sys
import os
import hashlib
import threading

binary_files = [".jpg", ".png", ".gif", ".pdf", ".doc", ".docx", ".xls", ".xlsx", ".ppt", ".pptx", ".zip", ".rar", ".exe", ".mp3", ".mp4", ".avi", ".wmv", ".flv", ".swf", ".iso", ".bin", ".dat", ".db", ".dbf", ".log", ".mdb", ".sav", ".sql", ".tar", ".xml"]

text_files = [".txt", ".py", ".c", ".cpp", ".h", ".hpp", ".java", ".cs", ".js", ".css", ".html", ".htm", ".php", ".asp", ".aspx", ".bat", ".cmd", ".sh", ".vb", ".vbs", ".rtf", ".csv", ".json", ".yaml", ".yml", ".md", ".markdown"]

class ClientUDP:
    def __init__(self, host, port):
        self.host = host
        self.server_port = port
        self.client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
        self.client.bind(('', 0))
        self.client_port = self.client.getsockname()[1]

    def start(self):
        print(f"[LISTENING]: Cliente iniciado em {self.host}:{self.client_port}")
        
        while True:
            # Pega o caminho do arquivo
            file_path = input("Digite o caminho do arquivo: ")

            # Verifica se o arquivo existe e é legível
            if not os.path.isfile(file_path) or not os.access(file_path, os.R_OK):
                print("Arquivo não encontrado ou não é legível")
                continue

            # Cria uma thread para enviar os pacotes ao servidor
            thread_envio = threading.Thread(target=self.envia_pacotes, args=(file_path,))
            thread_envio.start()

            # Aguarda a thread de envio terminar
            thread_envio.join()

    def envia_pacotes(self, file_path):
        # Pega o nome do arquivo
        file_name = os.path.basename(file_path)

        # Verifica se ele é texto ou binário
        ext = os.path.splitext(file_path)[1]

        if ext in text_files:
            file_type = 0
        elif ext in binary_files:
            file_type = 1
        else:
            print("Tipo de arquivo não suportado")
            return
        
        # Abre o arquivo
        with open(file_path, "rb") as file:
            # Pega o tamanho do arquivo
            file_size = os.path.getsize(file_path)
            print(file_size)

            # Calcula o número de pacotes
            num_packets = file_size // 1024
            if file_size % 1024 != 0:
                num_packets += 1

            # Calcula o checksum (SHA-1) do arquivo
            checksum = hashlib.sha1(file.read()).hexdigest()

            # Volta o ponteiro para o início do arquivo
            file.seek(0)

            # Envia os pacotes
            for i in range(num_packets):
                # Pega os dados do pacote
                data = file.read(1024)

                # Monta o datagrama
                datagram = self.monta_datagrama(i + 1, num_packets, checksum, file_type, file_name, data)

                # Envia o datagrama
                self.client.sendto(datagram, (self.host, self.server_port))
                print(f"[SENDING]: Pacote {i + 1}/{num_packets} enviado")



    def monta_datagrama(self, ordem, num_packets, checksum, file_type, file_name, data):
        """
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
        """

        # Monta o datagrama
        datagram = b''
        datagram += self.client_port.to_bytes(2, byteorder="big")
        datagram += self.server_port.to_bytes(2, byteorder="big")
        datagram += ordem.to_bytes(1, byteorder="big")
        datagram += (1 if ordem == num_packets else 0).to_bytes(1, byteorder="big")
        datagram += bytes.fromhex(checksum)
        datagram += file_type.to_bytes(1, byteorder="big")
        datagram += len(file_name).to_bytes(1, byteorder="big")

        # Preenche o nome do arquivo com espaços
        file_name = file_name.ljust(255, '\x00')
        datagram += file_name.encode()

        datagram += len(data).to_bytes(2, byteorder="big")

        # Preenche os dados com espaços
        if len(data) < 1024:
            data = data.ljust(1024, b'\x00')
        datagram += data

        #self.print_datagram(datagram)
        return datagram


    def print_datagram(self, datagram):
        print("Datagrama:")
        print(f"Porta de origem: {int.from_bytes(datagram[0:2], byteorder='big')}")
        print(f"Porta de destino: {int.from_bytes(datagram[2:4], byteorder='big')}")
        print(f"Ordem do pacote: {int.from_bytes(datagram[4:5], byteorder='big')}")
        print(f"Ultimo pacote: {int.from_bytes(datagram[5:6], byteorder='big')}")
        print(f"Checksum: {datagram[6:26].hex()}")
        print(f"Tipo de arquivo: {int.from_bytes(datagram[26:27], byteorder='big')}")
        print(f"Tamanho do nome do arquivo: {int.from_bytes(datagram[27:28], byteorder='big')}")
        print(f"Nome do arquivo: {datagram[28:283].decode()}")
        print(f"Tamanho do arquivo: {int.from_bytes(datagram[283:285], byteorder='big')}")
        print(f"Dados: {datagram[285:1309].decode()}")













if __name__ == "__main__":
    client = ClientUDP("localhost", 9999)
    client.start()