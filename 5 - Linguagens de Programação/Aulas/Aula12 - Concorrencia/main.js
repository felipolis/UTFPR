const { Worker } = require('worker_threads');

const worker = new Worker('./worker.js');     // cria o worker
worker.on('message', message => {             // recebe msg
  console.log('Mensagem recebida:', message);
})
worker.postMessage('Olá worker!')             // envia msg