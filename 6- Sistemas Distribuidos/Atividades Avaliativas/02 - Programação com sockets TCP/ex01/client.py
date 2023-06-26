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
import hashlib

class TCPClient:    # Classe para o cliente TCP
    def __init__(self):
        self.server_address = ('localhost', 6666)   # Endereço do servidor
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # Cria o socket

    def run(self):  # Método executado quando a thread é iniciada
        self.socket.connect(self.server_address)    # Conecta ao servidor
        print("Conectado ao servidor:", self.server_address)    # Exibe a mensagem

        try:
            while True:
                message = input("> ").replace(',', '')

                command = message.split()[0]
                if command == 'CONNECT':
                    user = message.split()[1]
                    password = message.split()[2]
                    message = f'CONNECT {user} {password}\n'.encode()
                    print(message)
                elif command == 'PWD':
                    message = b'PWD\n'
                elif command == 'CHDIR':
                    path = message.split()[1]
                    message = f'CHDIR {path}\n'.encode()
                elif command == 'GETFILES':
                    message = b'GETFILES\n'
                elif command == 'GETDIRS':
                    message = b'GETDIRS\n'
                elif command == 'EXIT':
                    message = b'EXIT\n'
                else:
                    print('Invalid command')
                    continue

                # print("Enviando mensagem:", message)
                self.socket.sendall(message)

                if command == 'EXIT':
                    break


                data = self.socket.recv(1024)
                print("Servidor disse:", data.decode('utf-8'))

        except ConnectionResetError:
            print("Conexão com o servidor perdida")
        except Exception as e:
            print("Ocorreu um erro:", e)

        finally:
            self.socket.close()
            print("Conexão com o servidor finalizada")


if __name__ == '__main__':
    client = TCPClient()    # Cria o cliente
    client.run()    # Executa o cliente
