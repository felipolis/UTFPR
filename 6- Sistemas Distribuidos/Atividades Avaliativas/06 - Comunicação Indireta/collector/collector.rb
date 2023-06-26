=begin 

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

=end

require 'json'
require 'bunny'
require 'csv'

# Configuração do RabbitMQ
rabbitmq_host = 'localhost'
rabbitmq_queue = 'tweets'

# Configuração do Twitter
twitter_file = '../data/tweets.csv'

# Conecta com o RabbitMQ
connection = Bunny.new(host: rabbitmq_host)
connection.start
channel = connection.create_channel

# Cria a fila
queue = channel.queue(rabbitmq_queue)

# Lê o arquivo de tweets
puts "Lendo tweets do arquivo #{twitter_file}..."
tweets = CSV.read(twitter_file, headers: true, encoding: 'ISO-8859-1')

# Faz o embaralhamento de todos os tweets
tweets = tweets.to_a.shuffle

# Pega apenas os 100 primeiros tweets
tweets = tweets.first(100)

# Envia os tweets para a fila
puts "Enviando #{tweets.length} tweets para a fila #{rabbitmq_queue}..."
tweets.each do |tweet|
  channel.default_exchange.publish(tweet[3].to_json, routing_key: rabbitmq_queue)
end

puts "#{tweets.length} tweets enviados para a fila #{rabbitmq_queue}."
connection.close
