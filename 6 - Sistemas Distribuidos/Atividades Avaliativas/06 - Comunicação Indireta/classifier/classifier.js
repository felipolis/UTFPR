/* 
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
*/


const amqp = require('amqplib/callback_api');
const fs = require('fs');

// Configuração do RabbitMQ
const rabbitmqHost = 'amqp://localhost';
const rabbitmqQueue = 'tweets';

let connection; // Variável para armazenar a conexão com o RabbitMQ
let channel; // Variável para armazenar o canal

function processaTweet(tweet) {
  /**
   * Processa um tweet.
   */

  // Transforma em string
  const tweetString = JSON.stringify(tweet);

  const positive = ['love', 'good', 'happy', 'great', 'nice', 'excellent', 'wonderful', 'amazing'];
  const negative = ['upset', 'kill', 'hate', 'bad', 'sad', 'mad', 'angry', 'shame'];

  // Separa as palavras
  const words = tweetString.split(' ');

  // Conta as palavras positivas
  let positiveCount = 0;
  words.forEach(word => {
    if (positive.includes(word)) {
      positiveCount++;
    }
  });

  // Conta as palavras negativas
  let negativeCount = 0;
  words.forEach(word => {
    if (negative.includes(word)) {
      negativeCount++;
    }
  });

  // Retorna o resultado
  if (positiveCount > negativeCount) {
    return 'positive';
  } else if (negativeCount > positiveCount) {
    return 'negative';
  } else {
    return 'neutral';
  }
}

function consumeTweets() {
  /**
   * Consome os tweets da fila.
   */

  // Conecta com o RabbitMQ
  amqp.connect(rabbitmqHost, (error, conn) => {
    if (error) {
      throw error;
    }

    // armazena a conexão
    connection = conn;

    // Cria o canal
    connection.createChannel((error, ch) => {
      if (error) {
        throw error;
      }

      // Armazena o canal
      channel = ch;


      // Cria a fila
      channel.assertQueue(rabbitmqQueue, { durable: false });

      // Callback para o consumo de mensagens
      const callback = (msg) => {
        const tweet = JSON.parse(msg.content.toString());
        const topic = processaTweet(tweet);
        publishTweet(topic, tweet);
      };

      // Consume os tweets
      console.log(`Consumindo tweets da fila ${rabbitmqQueue}...`);
      channel.consume(rabbitmqQueue, callback, { noAck: true });
    });
  });
}

function publishTweet(topic, tweet) {
  /**
   * Publica um tweet em um tópico.
   */
    // Cria o tópico
    channel.assertExchange(topic, 'fanout', { durable: false });

    // Publica o tweet
    channel.publish(topic, '', Buffer.from(JSON.stringify(tweet)));

}

function main() {
  consumeTweets();
}

main();
