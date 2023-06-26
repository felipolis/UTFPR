"""
DESCRIÇÃO:
    Fazer um chat P2P que possibilite os clientes trocarem mensagens entre si.
    As mensagens possuem o formato:
        - tipo de mensagem [1 byte]
        - tamanho apelido (tam_apl) [1 byte]
        - apelido [tam_apl (1 a 64) bytes ]
        - tamanho mensagem (tam_msg) [1 byte]
        - mensagem [tam_msg bytes]

    Os tipos de mensagem são:
        1: mensagem normal
        2: emoji
        3: URL
        4: ECHO (envia e recebe a mesma mensagem para indicar que usuário está ativo).

AUTOR: Felipe Archanjo da Cunha Mendes

DATA: 07/04/2023

"""

import socket
import threading
import struct
import threading



class ChatUDP:
    def __init__(self, username):
        self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.username = username
        self.port = 0
        self.friend = ''
        self.friend_port = 0


    def run(self):
        # inicia o servidor UDP
        self.udp_socket.bind(('', 0))
        self.port = self.udp_socket.getsockname()[1]
        print(f'Ouvindo na porta {self.port}')


        # Pergunta ao usuario qual a porta que ele quer se conectar
        friend = input('Digite o nome do amigo que deseja se conectar: ')
        self.friend = friend
        
        port = input('Digite a porta que deseja se conectar: ')
        port = int(port)
        self.friend_port = port

        # Criação da thread para receber mensagens UDP
        thread = threading.Thread(target=self.receive_udp_messages)
        thread.start()
        # pega o pid da thread

        while True:
            # Envia uma mensagem:
            """
            > /msg <mensagem>: Mensgaem de texto comum
            > /emoji <emoji>: Mensagem de emoji
            > /url <url>: Mensagem de URL
            > /echo <msg>: Mensagem de ECHO
            """
            msg = input('> ')
            if msg.startswith('/msg'):
                # Envia o tipo de mensagem
                self.udp_socket.sendto(struct.pack('B', 1), ('localhost', port))

                # Envia o tamanho do username
                self.udp_socket.sendto(struct.pack('B', len(self.username)), ('localhost', port))

                # Envia o username
                self.udp_socket.sendto(self.username.encode(), ('localhost', port))

                # Envia o tamanho da mensagem
                self.udp_socket.sendto(struct.pack('B', len(msg[5:])), ('localhost', port))

                # Envia a mensagem
                self.udp_socket.sendto(msg[5:].encode(), ('localhost', port))

            elif msg.startswith('/emoji'):
                # Envia o tipo de mensagem
                self.udp_socket.sendto(struct.pack('B', 2), ('localhost', port))

                # Envia o tamanho do username
                self.udp_socket.sendto(struct.pack('B', len(self.username)), ('localhost', port))

                # Envia o username
                self.udp_socket.sendto(self.username.encode(), ('localhost', port))

                # Envia o tamanho da mensagem
                self.udp_socket.sendto(struct.pack('B', len(msg[7:])), ('localhost', port))

                # Envia a mensagem
                self.udp_socket.sendto(msg[7:].encode(), ('localhost', port))

            elif msg.startswith('/url'):
                # Envia o tipo de mensagem
                self.udp_socket.sendto(struct.pack('B', 3), ('localhost', port))

                # Envia o tamanho do username
                self.udp_socket.sendto(struct.pack('B', len(self.username)), ('localhost', port))

                # Envia o username
                self.udp_socket.sendto(self.username.encode(), ('localhost', port))

                # Envia o tamanho da mensagem
                self.udp_socket.sendto(struct.pack('B', len(msg[5:])), ('localhost', port))

                # Envia a mensagem
                self.udp_socket.sendto(msg[5:].encode(), ('localhost', port))

            elif msg.startswith('/echo'):
                # Envia o tipo de mensagem
                self.udp_socket.sendto(struct.pack('B', 4), ('localhost', port))

                # Envia o tamanho do username
                self.udp_socket.sendto(struct.pack('B', len(self.username)), ('localhost', port))

                # Envia o username
                self.udp_socket.sendto(self.username.encode(), ('localhost', port))

                # Envia o tamanho da mensagem
                self.udp_socket.sendto(struct.pack('B', len(msg[6:])), ('localhost', port))

                # Envia a mensagem
                self.udp_socket.sendto(msg[6:].encode(), ('localhost', port))
            elif msg.startswith('/exit'):
                print('Saindo...')
                exit()
            else:
                print('Comando inválido')
    
    def receive_udp_messages(self):
        while True:
            # Recebe o tipo de mensagem
            msg_type = self.udp_socket.recv(1)
            msg_type = struct.unpack('B', msg_type)[0]

            # Recebe o tamanho do username
            username_size = self.udp_socket.recv(1)
            username_size = struct.unpack('B', username_size)[0]

            # Recebe o username
            username = self.udp_socket.recv(username_size)
            username = username.decode()

            # Recebe o tamanho da mensagem
            msg_size = self.udp_socket.recv(1)
            msg_size = struct.unpack('B', msg_size)[0]

            # Recebe a mensagem
            msg = self.udp_socket.recv(msg_size)
            msg = msg.decode()

            # Verifica se a mensagem é do usuário que está conectado
            if username == self.username or username == self.friend:
                if msg_type == 1:
                    print(f'{username}: [MSG] {msg}\n> ', end='')
                elif msg_type == 2:
                    print(f'{username}: [EMOJI] {msg}\n> ', end='')
                elif msg_type == 3:
                    print(f'{username}: [URL] {msg}\n> ', end='')
                elif msg_type == 4:
                    if username == self.friend:
                        print(f'{username}: [ECHO] {msg}\n> ', end='')
                        # Envia de volta a mensagem
                        self.udp_socket.sendto(struct.pack('B', 4), ('localhost', self.friend_port))
                        self.udp_socket.sendto(struct.pack('B', len(username)), ('localhost', self.friend_port))
                        self.udp_socket.sendto(username.encode(), ('localhost', self.friend_port))
                        self.udp_socket.sendto(struct.pack('B', len(msg)), ('localhost', self.friend_port))
                        self.udp_socket.sendto(msg.encode(), ('localhost', self.friend_port))
                    else:
                        print(f'{username}: [ECHO] {msg}\n', end='')

                else:
                    print('Tipo de mensagem inválido')

def main():
    # Recebe username
    username = input('Digite seu usuario: ')

    # Cria o ChatUDP
    chat_udp = ChatUDP(username)

    # Inicia o ChatUDP
    chat_udp.run()


if __name__ == '__main__':
    main()

