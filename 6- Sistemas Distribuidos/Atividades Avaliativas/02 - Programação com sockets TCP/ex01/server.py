"""
DESCRIÇÃO:
    Faça um servidor para processar as seguintes mensagens dos clientes. O servidor deve suportar mensagens de múltiplos clientes. Use o TCP. As mensagens de solicitação estão no formato String UTF:

    CONNECT user, password
    * Conecta o usuário user a sua área no servidor se a senha password conferir e o usuário user existir. Em caso de sucesso, devolver SUCCESS como String UTF. Em caso de falha, devolver ERROR. Obs: password deve ser enviado o hash em SHA-512.

    PWD
    * Devolve o caminho corrente (PATH) usando String UTF separando os diretórios por barra(/).

    CHDIR path
    * Altera o diretório corrente para path, retornado uma String UTF, SUCCESS, no caso de sucesso, e ERROR, no caso de erro.

    GETFILES
    * Devolve os arquivos do diretório corrente no servidor.
    Formato:
        * devolve um inteiro indicando o número de arquivos como String UTF.
        * devolve cada arquivo como uma String UTF.

    GETDIRS
    * Devolve os diretórios do diretório corrente no servidor.
    Formato:
        * devolve um inteiro indicando o número de diretórios como String UTF.
        * devolve cada diretório como uma String UTF.

    EXIT
    * Finaliza a conexão

AUTOR: Felipe Archanjo da Cunha Mendes

DATA: 02/04/2023
"""

import socket
import threading
import hashlib
import os
import selectors
import types

# Dicionário para armazenar informações dos usuários
USERS = {
    "user1": {"password": hashlib.sha512("123".encode()).hexdigest()},
    "user2": {"password": hashlib.sha512("123".encode()).hexdigest()},
}

class ClientThread(threading.Thread): # Thread para atender um cliente
    def __init__(self, clientSocket): # Construtor
        threading.Thread.__init__(self) # Inicializa a classe Thread
        self.clientSocket = clientSocket    # Socket do cliente

    def authenticate_user(self, user, password):
        if user in USERS:
            hashed_password = hashlib.sha512(password.encode()).hexdigest()
            if USERS[user]["password"] == hashed_password:
                return True
        return False

    def get_files_list(self, path):
        return [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]
    
    def get_dirs_list(self, path):
        return [d for d in os.listdir(path) if os.path.isdir(os.path.join(path, d))]
    
    def process_message(self, buffer):
        message_parts = buffer.strip().split(' ')
        command = message_parts[0]
        if command == 'CONNECT':
            user = message_parts[1]
            password = message_parts[2]
            if self.authenticate_user(user, password):
                return "SUCCESS"
            else:
                return "ERROR"
        elif command == 'PWD':
            return os.path.abspath(os.getcwd()).replace('/', '\\')
        elif command == 'CHDIR':
            new_dir = message_parts[1]
            if os.path.isdir(new_dir):
                os.chdir(new_dir)
                return "SUCCESS"
            else:
                return "ERROR"
        elif command == 'GETFILES':
            files_list = self.get_files_list(os.getcwd())
            response = [str(len(files_list))]
            response += files_list
            return "\n".join(response)
        elif command == "GETDIRS":
            dirs_list = self.get_dirs_list(os.getcwd())
            response = [str(len(dirs_list))]
            response += dirs_list
            return "\n".join(response)
        elif command == "EXIT":
            return "EXIT"
        else:
            return "ERROR"


    def run(self):  # Método executado quando a thread é iniciada
        try:
            print("Cliente conectado... criando thread...")
            # cria objetos de leitura e escrita
            in_data = self.clientSocket.recv(1024) # aguarda m          ensagem do cliente
            buffer = in_data.decode('utf-8') # decodifica a mensagem
            print("Cliente disse: " + buffer)   # exibe a mensagem

            response = self.process_message(buffer)

            while True:
                if response == "EXIT":
                    break

                # responde ao cliente
                out_data = response
                self.clientSocket.sendall(out_data.encode('utf-8'))

                # aguarda nova mensagem do cliente
                in_data = self.clientSocket.recv(1024) # aguarda mensagem do cliente
                buffer = in_data.decode('utf-8') # decodifica a mensagem
                print("Cliente disse: " + buffer)   # exibe a mensagem

                response = self.process_message(buffer)

        except ConnectionResetError as e:
            print("Erro de conexão: ", e)

        finally:
            self.clientSocket.close()
            print("Thread comunicação cliente finalizada.")

def main():
    try:
        serverPort = 6666

        # cria um socket e mapeia a porta para aguardar conexões
        listenSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        listenSocket.bind(('', serverPort))
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
