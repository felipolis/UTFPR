----------------- Como Executar -----------------

1. Instale o RabbitMQ
    Windows - https://www.rabbitmq.com/install-windows.html
    Linux - https://www.rabbitmq.com/install-debian.html

2. Instale o python3
    Windows/linux - https://www.python.org/downloads/

3. Instale o Ruby
    Windows/linux - https://www.ruby-lang.org/en/downloads/

4. Instale o NodeJS
    Windows/linux - https://nodejs.org/en/download/

3. Instale as dependências
    PYTHON:
        $ cd clients
        $ pip install -r requirements.txt
    
    RUBY:
        $ cd collector
        $ bundle install
    
    NODEJS:
        $ cd classifier
        $ npm install


4. Execute o projeto
    ASSINANTE:
        -> Você pode cadastrar ou logar com um usuário no sistema e se registrar em um ou mais tópicos
        -> Ao cadastrar um usuario, será criado um arquivo ./etc/shadow.txt com o username,senha,topicos
            $ cd clients
            $ python3 auth-subscriber.py

        -> Ou você pode utilizar um usuario guest
            $ cd clients
            $ python3 guest-subscriber.py

    CLASSIFICADOR:
        -> Aquele que classifica as mensagens recebidas pelo coletor e as cadastra em tópicos
            $ cd classifier
            $ npm start

    COLETOR:
        -> O coletor pega 100 tweets do dataset ./data/tweets.csv e os envia para o classificador por meio de uma fila de mensagens
        -> Link do dataset: https://www.kaggle.com/datasets/jp797498e/twitter-entity-sentiment-analysis
            $ cd collector
            $ ruby collector.rb



