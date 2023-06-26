"""
DESCRIÇÃO:
    1. Os coletores coletam tweets por meio de palavras-chave que descrevem os tópicos de interesse.
    2. O coletor envia os tweets para uma fila em um serviço de mensagens (ActiveMQ, Qpid ou RabbitMQ).
    3. Os classificadores consomem os tweets da fila e processam as mensagens para identificar o tópico principal do
    tweet.
    4. Os classificadores publicam os tweets no tópico específico (tweets não classificados são descartados).
    5. Os assinantes são notificados com os tweets de interesse (que foram assinados).
    Observação: Os assinantes devem assinar os tópicos de interesse previamente no serviço para começar a
    receber as notificações.

    O serviço pode ser implementado em qualquer linguagem de programação. Os serviços de mensagens deve ser o RabbitMQ.

    O serviço deve prover as seguintes funcionalidades:
    • Coleta de tweets a partir do sítio original ou a partir da leitura de um arquivo (json).
    • Envio dos tweets coletados para uma fila de mensagens. Opcionalmente os tweets podem ser pré-processados
    (filtrados, normalizados, reduzidos).
    • Consumo e processamento dos tweets por módulos do classificador. O classificador pode ser bem simples, usar
    palavras-chave para identificar o tópico.
    • Assinatura de clientes (Assinantes) para um ou mais tópicos no serviço de mensagens.
    • Recebimento dos tópicos de interesse pelos assinantes.

    # Os tweets estao em um arquivo chamado tweets.csv

AUTOR:
    - Felipe Archanjo da Cunha Mendes

DATA: 12/05/2023

"""

# assinante.py
import json
import pika
import threading
import hashlib
import os

# Configuração do RabbitMQ
rabbitmq_host = "localhost"
rabbitmq_queue = "tweets"


def subscribe_topic(topic):
        print(f"Assinando tópico {topic}...")
    
        # Conecta com o RabbitMQ
        connection = pika.BlockingConnection(pika.ConnectionParameters(host=rabbitmq_host))
        channel = connection.channel()
    
        # Cria o tópico
        channel.exchange_declare(exchange=topic, exchange_type="fanout")
    
        # Cria a fila
        result = channel.queue_declare(queue="", exclusive=True)
        queue_name = result.method.queue
    
        # Faz o bind
        channel.queue_bind(exchange=topic, queue=queue_name)
    
        def callback(ch, method, properties, body):
    
            # Processa o tweet
            tweet = json.loads(body)
            print(f"Tweet recebido ({topic}): {tweet}\n")
    
        # Consume os tweets
        print(f"Consumindo tweets do tópico {topic}...")
        channel.basic_consume(queue=queue_name, on_message_callback=callback, auto_ack=True)
        channel.start_consuming()
        print(f"Consumo finalizado.")



"""  shadow.txt:

username password topic1 topic2 topic3 ... topicN
...

"""

if __name__ == "__main__":
    topicos = ["positive", "negative", "neutral"]

    myTopics = []

    # Tela de login ou cadastro
    print("Bem vindo ao sistema de notificação de tweets!")
    while True:
        print("1 - Login")
        print("2 - Cadastro")
        print("0 - Sair")
        opcao = int(input("Opção: "))

        if opcao == 0:
            exit()
        elif opcao == 1:
            while True:
                username = input("Digite seu nome de usuário: ")
                password = input("Digite sua senha: ")

                if username == "" or password == "":
                    print("Usuário ou senha inválidos")
                    break
                else:
                    # Verifica se o arquivo ./etc/shadow.txt existe
                    try:
                        with open("./etc/shadow.txt", "r") as shadow:
                            for line in shadow.readlines():
                                line = line.strip()
                                line = line.split(" ")
                                
                                quant_topicos = len(line) - 2

                                if line[0] == username and line[1] == hashlib.sha256(password.encode()).hexdigest():
                                    print("Login realizado com sucesso!")
                                    myTopics = line[2:]
                                    for topic in myTopics:
                                        thread = threading.Thread(target=subscribe_topic, args=(topic,))
                                        thread.start()
                                    exit()
                            else:
                                print("\n[ERROR]: Usuário ou senha inválidos\n")
                                break
                    except FileNotFoundError:
                        print("Usuário ou senha inválidos")
                        break
        elif opcao == 2:
            while True:
                username = input("Digite seu nome de usuário: ")
                password = input("Digite sua senha: ")
                confirm_password = input("Confirme sua senha: ")

                if username == "" or password == "" or confirm_password == "":
                    print("Usuário ou senha inválidos")
                elif password != confirm_password:
                    print("As senhas não conferem")
                else:
                    # Verifica se o diretorio ./etc existe
                    try:
                        os.mkdir("./etc")
                    except FileExistsError:
                        pass


                    # Primeiro verifica se o usuario ja existe
                    try:
                        with open("./etc/shadow.txt", "r") as shadow:
                            for line in shadow.readlines():
                                line = line.strip()
                                line = line.split(" ")
                                
                                if line[0] == username:
                                    print("Usuário já existe")
                                    break
                    except FileNotFoundError:
                        pass

                    # Cadastra nos topicos
                    while True:
                        print("Digite o tópico que deseja assinar: ")
                        for index, topic in enumerate(topicos):
                            print(f"{index + 1} - {topic}")
                        print("0 - Confirmar")
                        opcao = int(input("Opção: "))

                        if opcao == 0:
                            break
                        elif opcao > 0 and opcao <= len(topicos):
                            if topicos[opcao - 1] in myTopics:
                                print(f"Você já está inscrito no tópico {topicos[opcao - 1]}")
                            else:
                                myTopics.append(topicos[opcao - 1])
                                print(f"Você foi inscrito no tópico {topicos[opcao - 1]}")
                        else:
                            print("Opção inválida")

                    # Se o usuario nao existe, cria o arquivo
                    try:
                        with open("./etc/shadow.txt", "a") as shadow:
                            # Escreve os dados em uma linha vazia no arquivo
                            shadow.write("\n")

                            # Escreve o username e a senha
                            shadow.write(f"{username} {hashlib.sha256(password.encode()).hexdigest()}")

                            # Escreve os topicos
                            for topic in myTopics:
                                shadow.write(f" {topic}")
                    except FileNotFoundError:
                        pass

                    print("Cadastro realizado com sucesso!")
                    break
        else:
            print("Opção inválida")

