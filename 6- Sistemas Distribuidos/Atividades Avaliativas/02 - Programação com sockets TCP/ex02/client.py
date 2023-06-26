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

import socket
import struct
import os
import tkinter as tk
from tkinter import simpledialog
from tkinter import ttk



class TCPClient:
    def __init__(self):
        self.server_address = ('localhost', 6666)
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    def receive_response(self, buffer=''):
        print("Recebendo resposta do servidor")
        # Receber (message type|command identifier|status code)
        response = self.client_socket.recv(3)
        message_type, command_identifier, status_code = struct.unpack('BBB', response)

        if message_type == 2:
            if command_identifier == 1:
                if status_code == 1:
                    print("Arquivo adicionado com sucesso")
                elif status_code == 2:
                    print("Erro ao adicionar arquivo")
            elif command_identifier == 2:
                if status_code == 1:
                    print("Arquivo deletado com sucesso")
                elif status_code == 2:
                    print("Erro ao deletar arquivo")
            elif command_identifier == 3:
                if status_code == 1:
                    # Receber (number of files|files)
                    response = self.client_socket.recv(2)
                    number_of_files = struct.unpack('>H', response)[0]
                    files = []
                    for i in range(number_of_files): # (filename size|filename)
                        response = self.client_socket.recv(1)
                        filename_size = struct.unpack('B', response)[0]

                        response = self.client_socket.recv(filename_size)
                        filename = struct.unpack(str(filename_size) + 's', response)[0].decode()
                        files.append((filename, filename_size))
                    self.window_list_files(number_of_files, files)
                    print("Lista de arquivos recebida com sucesso")
                elif status_code == 2:
                    print("Erro ao receber lista de arquivos")
            elif command_identifier == 4:
                if status_code == 1:
                    # Criar pasta para armazenar os downloads
                    download_path = os.path.join(os.getcwd(), "downloads")
                    if not os.path.exists(download_path):
                        os.makedirs(download_path)

                    # Receber (file size|file data)
                    filename = buffer
                    response = self.client_socket.recv(4)
                    file_size = struct.unpack('>I', response)[0]

                    file_data = b''
                    while len(file_data) < file_size:
                        response = self.client_socket.recv(1)
                        file_data += response
                    with open(os.path.join(download_path, filename), 'wb') as f:
                        f.write(file_data)
                    print("Arquivo recebido com sucesso")
                elif status_code == 2:
                    print("Erro ao receber arquivo")
    
    def add_file(self, filename, file_data, addWindow):
        # Fecha a janela de adicionar arquivo
        addWindow.destroy()
        print (len(file_data.strip()))
        # Enviar (message type|command identifier|filename size|filename|file size|file data)
        self.client_socket.sendall(struct.pack('BBB', 1, 1, len(filename)) + filename.encode() + struct.pack('>I', len(file_data.strip())) + file_data.strip().encode())
        self.receive_response()

    def delete_file(self, filename, deleteWindow):
        # Fecha a janela de deletar arquivo
        deleteWindow.destroy()

        # Enviar (message type|command identifier|filename size|filename)
        self.client_socket.sendall(struct.pack('BBB', 1, 2, len(filename)) + filename.encode())
        self.receive_response()

    def list_files(self):
        # Enviar (message type|command identifier|filename size|filename)
        self.client_socket.sendall(struct.pack('BBB', 1, 3, 0))
        self.receive_response()
    
    def download_file(self, filename, downloadWindow):
        # Fecha a janela de baixar arquivo
        downloadWindow.destroy()

        # Enviar (message type|command identifier|filename size|filename)
        self.client_socket.sendall(struct.pack('BBB', 1, 4, len(filename)) + filename.encode())
        self.receive_response(filename)
    
    def window_list_files(self, number_of_files, files):
        """
        Fazer uma janela que liste os arquivos e seus tamanhos
        """
        listWindow = tk.Tk()
        listWindow.title("Lista de arquivos")
        listWindow.geometry("400x400")
        listWindow.config(bg="black")

        titleLabel = tk.Label(listWindow, text="Arquivos:", font=("Arial", 16), fg="white", bg="black")
        titleLabel.pack(side="top", pady=10)
        for i in range(number_of_files):
            filename, filename_size = files[i]
            fileFrame = tk.Frame(listWindow, bg="black")
            filenameLabel = tk.Label(fileFrame, text=filename, font=("Arial", 16), fg="white", bg="black")
            sizeLabel = tk.Label(fileFrame, text="(" + str(filename_size) + " bytes)", font=("Arial", 16), fg="white", bg="black")
            filenameLabel.pack(side=tk.LEFT)
            sizeLabel.pack(side=tk.RIGHT)
            fileFrame.pack()

        listWindow.mainloop()


    def window_add_file(self, menuWindow):
        """
        Fazer uma janela com os campos:
        1 - Nome do arquivo
        2 - conteudo do arquivo
        3 - Um botão "Criar arquivo"
        """
        # Fecha a janela do menu
        menuWindow.destroy()
        
        addWindow = tk.Tk()
        addWindow.title("Adicionar arquivo")
        addWindow.geometry("400x400")
        addWindow.config(bg="black")

        nameLabel = tk.Label(addWindow, text="Nome do arquivo:", font=("Arial", 16), fg="white", bg="black")
        nameEntry = tk.Entry(addWindow, font=("Arial", 16), width=20)

        contentLabel = tk.Label(addWindow, text="Conteúdo do arquivo:", font=("Arial", 16), fg="white", bg="black")
        contentText = tk.Text(addWindow, font=("Arial", 16), width=25, height=5)

        createBtn = tk.Button(addWindow, text="Criar arquivo", command=lambda: [self.add_file(nameEntry.get(), contentText.get("1.0", "end"), addWindow)], font=("Arial", 16), height=2, width=30)

        nameLabel.pack(side="top", pady=10)
        nameEntry.pack(side="top", pady=10)
        contentLabel.pack(side="top", pady=10)
        contentText.pack(side="top", pady=10)
        createBtn.pack(side="top", pady=10)


    def window_delete_file(self):
        """
        1 - campo para o nome do arquivo
        2 - botão "Deletar arquivo"
        """
        # Cria a janela para deletar um arquivo
        deleteWindow = tk.Tk()
        deleteWindow.title("Deletar arquivo")
        deleteWindow.geometry("400x150")
        deleteWindow.config(bg="black")

        # Cria o label "Nome do arquivo"
        nameLabel = tk.Label(deleteWindow, text="Nome do arquivo:", font=("Arial", 14), fg="white", bg="black")
        nameLabel.pack(side="top", padx=10, pady=10)

        # Cria o campo de entrada para o nome do arquivo
        nameEntry = tk.Entry(deleteWindow, font=("Arial", 14), width=30)
        nameEntry.pack(side="top", padx=10, pady=5)

        # Cria o botão "Deletar arquivo"
        deleteBtn = tk.Button(deleteWindow, text="Deletar arquivo", command=lambda: self.delete_file(nameEntry.get(), deleteWindow), font=("Arial", 16), height=2, width=30)
        deleteBtn.pack(side="top", pady=10)

        deleteWindow.mainloop()

    def window_download_file(self):
        # create a new window
        downloadWindow = tk.Toplevel()
        downloadWindow.title("Download File")
        downloadWindow.geometry("400x200")
        downloadWindow.config(bg="black")

        # create a label and text entry field for the file name
        nameLabel = tk.Label(downloadWindow, text="File Name", font=("Arial", 14), fg="white", bg="black")
        nameLabel.pack(pady=(20, 5))
        nameEntry = tk.Entry(downloadWindow, font=("Arial", 14), width=30)
        nameEntry.pack()

        # create a button to download the file with the specified name
        downloadBtn = tk.Button(downloadWindow, text="Download", command=lambda: self.download_file(nameEntry.get(), downloadWindow), font=("Arial", 14), height=2, width=20)
        downloadBtn.pack(pady=(20, 0))

        # run the window
        downloadWindow.mainloop()


    def create_menu(self):
        """
        Fazer um menu com tkinter com as opções:
        1 - Adicionar arquivo
        2 - Deletar arquivo
        3 - Listar arquivos
        4 - Fazer download de um arquivo
        """
        menuWindow = tk.Tk()
        menuWindow.title("Menu") # Define o título da janela
        menuWindow.geometry("400x500") # Define o tamanho da janela
        menuWindow.config(bg="black") # Muda a cor de fundo da janela para preto
        menuWindow.eval('tk::PlaceWindow . center') # Centraliza a janela

        # Define o estilo dos botões
        style = ttk.Style()
        style.configure("TButton", padding=10, relief="flat", foreground="blue", background="gray")

        # Cria o label "Escolha uma opção"
        optionLabel = tk.Label(menuWindow, text="Escolha uma opção", font=("Arial", 20), fg="white", bg="black")

        # Cria os botões
        addBtn = tk.Button(menuWindow, text="Adicionar arquivo", command=lambda: self.window_add_file(menuWindow), font=("Arial", 16), height=2, width=30, )
        deleteBtn = tk.Button(menuWindow, text="Deletar arquivo", command=self.window_delete_file, font=("Arial", 16), height=2, width=30, )
        listBtn = tk.Button(menuWindow, text="Listar arquivos", command=self.list_files, font=("Arial", 16), height=2, width=30, )
        downloadBtn = tk.Button(menuWindow, text="Fazer download de um arquivo", command=self.window_download_file, font=("Arial", 16), height=2, width=30, )

        # Define o layout dos botões com espaço entre eles e centralizados
        optionLabel.pack(side="top", pady=(50, 10))
        addBtn.pack(side="top", pady=(50, 10))
        deleteBtn.pack(side="top", pady=10)
        listBtn.pack(side="top", pady=10)
        downloadBtn.pack(side="top", pady=10)

        menuWindow.mainloop()


    def run(self):
        self.client_socket.connect(self.server_address)
        print(f"Conectado ao servidor {self.server_address[0]} na porta {self.server_address[1]}")

        try:
            while True:
                self.create_menu()
        finally:
            self.client_socket.close()
            print("Conexão encerrada")

if __name__ == "__main__":
    client = TCPClient()
    client.run()



