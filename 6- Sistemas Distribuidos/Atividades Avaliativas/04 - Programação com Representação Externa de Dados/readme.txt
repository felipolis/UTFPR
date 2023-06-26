
-------------------- COMO EXECUTAR --------------------
1. Instalar o NodeJS (8.13.0) e o Python3 (3.11.1)

    - NodeJS: https://nodejs.org/en/download/
    - Python3: https://www.python.org/downloads/

    - Verificar se o NodeJS e o Python3 estao instalados:
    $ node -v
    $ python3 -V

    - Caso nao estejam instalados, instalar o NodeJS e o Python3

2. Instalar o compilador do protobuf:
    - Disponiveel no diretorio ./downloads

3. Compilar o arquivo proto:
    $ protoc movies.proto --js_out=import_style=commonjs,binary:./server --python_out=./client

4. Instalar as dependencias do cliente PYTHON:
    $ cd client
    $ pip install -r requirements.txt

5. Instalar as dependencias do servidor NODE:
    $ cd server
    $ npm install

6. Configurar o arquivo .env:
    $ cd server
    $ cp .env.example .env

    - Adicione a URL do banco de dados de filmes no MongoDB (ATLAS)

7. Executar o servidor:
    $ cd server
    $ npm start

8. Executar o cliente:
    $ cd client
    $ python client.py

