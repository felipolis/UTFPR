python -m grpc_tools.protoc --python_out=. --grpc_python_out=. movies.proto

-------------------- COMO EXECUTAR --------------------
1. Instalar o NodeJS (8.13.0) e o Python3 (3.11.1)

    - NodeJS: https://nodejs.org/en/download/
    - Python3: https://www.python.org/downloads/

    - Verificar se o NodeJS e o Python3 estao instalados:
    $ node -v
    $ python3 -V

2. Instalar dependencias do NodeJS e do Python3

    - NodeJS:
    $ cd server
    $ npm install

    - Python3:
    $ pip install requirements.txt

3. Compilar o arquivo proto

    - NodeJS: O codigo compilado é gerado em tempo de execucao, portanto nao é necessario compilar o arquivo proto manualmente para o NodeJS.

    - Python3:
    $ python -m grpc_tools.protoc --python_out=. --grpc_python_out=. --proto_path=../proto ../proto/movies.proto

4. Executar o servidor
    
    - NodeJS:
    $ cd server
    $ node server.js

5. Executar o cliente

    - Python3:
    $ cd client
    $ python client.py
    


