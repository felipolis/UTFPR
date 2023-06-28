const { parentPort } = require('worker_threads');

// Recebendo mensagens da thread principal
parentPort.on('message', message => {
  console.log('Mensagem recebida da thread principal:', message)
  parentPort.postMessage('Olá da thread worker!')
});