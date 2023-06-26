"""
Questão 2) Faça uma aplicação com um servidor que gerencia um conjunto de arquivos remotos entre múltiplos
usuários. O servidor deve responder aos seguintes comandos:
-> ADDFILE (1): adiciona um arquivo novo.
-> DELETE (2): remove um arquivo existente.
-> GETFILESLIST (3): retorna uma lista com o nome dos arquivos.
-> GETFILE (4): faz download de um arquivo.
O servidor deve registrar as ações em logs. Use uma biblioteca da linguagem específica para manipular os logs.
As solicitações possuem o seguinte cabeçalho em comum:
1 byte: requisição (1) – Message Type (0x01)
1 byte: código do comando – Command Identifier (0x01 a 0x04)
1 byte: tamanho do nome do arquivo – Filename Size
variável [0-255]: nome do arquivo em bytes – Filename
As respostas possuem o seguinte cabeçalho em comum:
1 byte: resposta (2) – Message Type (0x02)
1 byte: código do comando – Command Identifier (0x01 a 0x04)
1 byte: status code (1-SUCCESS, 2-ERROR) – Status Code
----
para o ADDFILE, adicionam-se os campos na solicitação:
4 bytes: tamanho do arquivo (big endian order) em bytes.
variável[1 a 232]: bytes do arquivo.
----
para o GETFILESLIST, adicionam-se os campos na resposta:
2 bytes: número de arquivos (big endian order)
Repete-se até terminar os nomes:
1 byte: tamanho do nome (1-255)
variável [1 a 255]: nome do arquivo
----
para o GETFILE. adicionam-se os campos na resposta:
4 bytes: tamanho do arquivo (big endian order) em bytes
variável [1 a 232]: bytes do arquivo.
* ao fazer download do arquivo, grave em uma pasta padrão.
* para enviar e receber arquivo façam envio e recebimento byte a byte.
"""

import struct
import logging
import socket
import threading
import os

HOST = 'localhost'
PORT = 6666

FILES_DIR = './files'

class ClientThread(threading.Thread): # Thread para atender um cliente
    def __init__(self, client_socket):  # Construtor
        threading.Thread.__init__(self) # Inicializa a thread
        self.client_socket = client_socket  # Socket do cliente
    
    # Função para adicionar um arquivo
    def add_file(self, conn, filename_size):    
        # Recebe o nome do arquivo
        filename = conn.recv(filename_size).decode('utf-8')

        # Recebe o tamanho do arquivo
        file_size = struct.unpack('>I', conn.recv(4))[0]
        logging.info(f'Criando arquivo: {filename} ({file_size} bytes)')
        print(f'Criando arquivo: {filename} ({file_size} bytes)')

        try:
            # Cria o arquivo
            with open(os.path.join(FILES_DIR, filename), 'wb') as f:
            # Recebe o arquivo byte a byte e escreve no arquivo
                for _ in range(file_size):
                    f.write(conn.recv(1))
                    print(f'{_ + 1}/{file_size}', end='\r')

            logging.info(f'Arquivo {filename} criado com sucesso!')
            print(f'Arquivo {filename} criado com sucesso!')

            # Envia a resposta de sucesso
            conn.sendall(struct.pack('>BBB', 2, 1, 1))
        except Exception as e:
            logging.error(f'Erro ao criar arquivo: {e}')
            print(f'Erro ao criar arquivo: {e}')

            # Envia a resposta de erro
            conn.sendall(struct.pack('>BBB', 2, 1, 2))

    # Função para remover um arquivo
    def delete_file(self, conn, filename_size):
        # Recebe o nome do arquivo
        filename = conn.recv(filename_size).decode('utf-8')
        logging.info(f'Removendo arquivo: {filename}')
        print(f'Removendo arquivo: {filename}')

        try:
            # Remove o arquivo
            os.remove(os.path.join(FILES_DIR, filename))
            logging.info(f'Arquivo {filename} removido com sucesso!')
            print(f'Arquivo {filename} removido com sucesso!')

            # Envia a resposta de sucesso
            conn.sendall(struct.pack('>BBB', 2, 2, 1))
        except FileNotFoundError:
            logging.error(f'Arquivo {filename} não encontrado!')
            print(f'Arquivo {filename} não encontrado!')

            # Envia a resposta de erro
            conn.sendall(struct.pack('>BBB', 2, 2, 2))

    # Função para obter a lista de arquivos
    def get_files_list(self, conn):
        logging.info('Enviando lista de arquivos')
        print('Enviando lista de arquivos')

        try:
            # Obtém a lista de arquivos
            files = os.listdir(FILES_DIR)
            logging.info(f'Arquivos encontrados: {files}')
            print(f'Arquivos encontrados: {files}')

            # Envia a resposta (resposta|comando|status|número de arquivos|tam_nome|nome|...)
            conn.sendall(struct.pack('>BBB', 2, 3, 1) + struct.pack('>H', len(files)))
            for filename in files:
                conn.sendall(struct.pack('>B', len(filename)) + filename.encode('utf-8'))
        except Exception as e:
            logging.error(f'Erro ao enviar lista de arquivos: {e}')
            print(f'Erro ao enviar lista de arquivos: {e}')

            # Envia a resposta de erro
            conn.sendall(struct.pack('>BBB', 2, 3, 2))

    # Função para obter um arquivo
    def get_file(self, conn, filename_size):
        # Recebe o nome do arquivo
        filename = conn.recv(filename_size).decode('utf-8')
        logging.info(f'Enviando arquivo: {filename}')
        print(f'Enviando arquivo: {filename}')

        try:
            # Abre o arquivo
            with open(os.path.join(FILES_DIR, filename), 'rb') as f:
                # Envia a resposta (resposta|comando|status|tamanho do arquivo|bytes do arquivo)
                conn.sendall(struct.pack('>BBB', 2, 4, 1) + struct.pack('>I', os.path.getsize(f.name)))
                for byte in f.read():
                    conn.sendall(struct.pack('>B', byte))
                logging.info(f'Arquivo {filename} enviado com sucesso!')
                print(f'Arquivo {filename} enviado com sucesso!')
        except FileNotFoundError:
            logging.error(f'Arquivo {filename} não encontrado!')
            print(f'Arquivo {filename} não encontrado!')

            # Envia a resposta de erro
            conn.sendall(struct.pack('>BBB', 2, 4, 2))

    def run(self):  # Método executado quando a thread é iniciada
        try:
            while True:
                logging.info("Conexão estabelecida com o cliente: %s", self.client_socket.getpeername()) # Logging da conexão
                print("Conexão estabelecida com o cliente: %s", self.client_socket.getpeername()) # Logging da conexão

                # Recebe o cabeçalho da mensagem
                header = self.client_socket.recv(3)
                message_type, command_id, filename_size = struct.unpack('>BBB', header)

                logging.info(f'Requisição recebida: Message Type={message_type}, Command={command_id}, Filename Size={filename_size}')
                print(f'Requisição recebida: Message Type={message_type}, Command={command_id}, Filename Size={filename_size}')

                # Executa o comando correspondente
                if command_id == 1: # ADDFILE
                    self.add_file(self.client_socket, filename_size)
                elif command_id == 2: # DELETE
                    self.delete_file(self.client_socket, filename_size)
                elif command_id == 3: # GETFILESLIST
                    self.get_files_list(self.client_socket)
                elif command_id == 4: # GETFILE
                    self.get_file(self.client_socket, filename_size)
                else:
                    logging.error(f'Comando inválido: {command_id}')
                    print(f'Comando inválido: {command_id}')
                    self.client_socket.close()
                    break
        except ConnectionResetError as e:
            logging.error("Conexão perdida com o cliente: %s", self.client_socket.getpeername())
            print("Conexão perdida com o cliente: %s", self.client_socket.getpeername())
        finally:
            self.client_socket.close()
            logging.info("Conexão encerrada com o cliente: %s", self.client_socket.getpeername())
            print("Conexão encerrada com o cliente: %s", self.client_socket.getpeername())

def main():

    # Configuração do logging
    logging.basicConfig(filename='server.log', level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

    if not os.path.exists(FILES_DIR):
        os.makedirs(FILES_DIR)

    try:
        # cria um socket e mapeia a porta para aguardar conexões
        listenSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        listenSocket.bind((HOST, PORT))
        listenSocket.listen()

        while True:
            print("Servidor aguardando conexão...")
            # aguarda conexões
            clientSocket, address = listenSocket.accept()

            # cria uma thread para atender a conexão
            c = ClientThread(clientSocket)

            # inicializa a thread
            c.start()

    except OSError as e:
        print("Erro de socket:", e)

    finally:
        listenSocket.close()

if __name__ == "__main__":
    main()
