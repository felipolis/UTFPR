//Variaveis Globais
var indice = 0;
var notas_valor = [200,100,50, 20, 10, 5, 2, 1];
var caixa_quantidade = [5, 5, 5, 5, 5, 5, 5, 5];
var valorCaixa = 0;
var aux3;

//Aqui Definiremos as ligações de paginas

onEvent("bot_entrar", "click", function( ) {
  setScreen("tela_menu");
});

onEvent("bot_cadastro", "click", function( ) {
  setScreen("tela_cadastro");
});

onEvent("bot_cancelar", "click", function( ) {
  setScreen("tela_menu");
});

onEvent("bot_lista", "click", function( ) {
  setScreen("tela_lista");
});

onEvent("bot_voltar", "click", function( ) {
  setScreen("tela_menu");
});

onEvent("bot_deposito", "click", function( ) {
  setScreen("tela_deposito");
});

onEvent("bot_cancelar1", "click", function( ) {
  setScreen("tela_menu");
});

onEvent("bot_saque", "click", function( ) {
  setScreen("tela_saque");
});

onEvent("bot_cancelar2", "click", function( ) {
  setScreen("tela_menu");
});


onEvent("bot_caixa", "click", function( ) {
  setScreen("tela_caixa");
});
onEvent("button4", "click", function( ) {
  setScreen("tela_menu");
});

//Aqui iremos criar as contas
var contaFulano = {};
contaFulano.nome = "Fulano";
contaFulano.sobrenome = "Oliveira";
contaFulano.cpf = "44499966600";
contaFulano.data = "14/12/1999";
contaFulano.estado = "SP";
contaFulano.cidade = "Campinas";
contaFulano.cep = "11000222";
contaFulano.endereco = "Rua lucifer, 666";
contaFulano.bairro = "jardim winchester";
contaFulano.saldo = 200;

var contas = [];
appendItem(contas, contaFulano);
mostrarContaAtual();
abastecer();

function abastecer() {
  valorCaixa = 0;
  for (var i = 0; i < 8; i++) {
    valorCaixa = valorCaixa + (notas_valor[i]*caixa_quantidade[i]);
  }
  mostrarContaAtual();
}





onEvent("bot_confirmar", "click", function( ) {
  var novaConta = {};
  
  novaConta.nome = getText("text_nome");
  novaConta.sobrenome = getText("text_sobrenome");
  novaConta.cpf = getText("text_cpf");
  novaConta.data = getText("text_data");
  novaConta.estado = getText("text_estado");
  novaConta.cidade = getText("text_cidade");
  novaConta.cep = getText("text_cep");
  novaConta.endereco = getText("text_endereco");
  novaConta.bairro = getText("text_bairro");
  novaConta.saldo = getNumber("text_saldo");
  
  appendItem(contas, novaConta);
  
  setText("text_nome", "");
  setText("text_sobrenome", "");
  setText("text_cpf", "");
  setText("text_data", "");
  setText("text_estado", "");
  setText("text_cidade", "");
  setText("text_cep", "");
  setText("text_endereco", "");
  setText("text_bairro", "");
  setText("text_saldo", "");
  
  setScreen("tela_menu");
});







//Aqui iremos criar a funcionalidade da listagem de contas
onEvent("bot_direita", "click", function( ) {
  indice++;
  indice = wrap(indice, 0, contas.length-1);
  mostrarContaAtual();
});
onEvent("bot_esquerda", "click", function( ) {
  indice--;
  indice = wrap(indice, 0, contas.length-1);
  mostrarContaAtual();
});
function mostrarContaAtual() {
  var nomeString = "Nome: " + (contas[indice]).nome;
  var sobrenomeString = "Sobrenome: " + (contas[indice]).sobrenome;
  var cpfString = "CPF: " + (contas[indice]).cpf;
  var dataString = "Nascimento: " + (contas[indice]).data;
  var estadoString = "Estado: " + (contas[indice]).estado;
  var cidadeString = "Cidade: " + (contas[indice]).cidade;
  var cepString = "CEP: " + (contas[indice]).cep;
  var enderecoString = "Endereço: " + (contas[indice]).endereco;
  var bairroString = "Bairro: " + (contas[indice]).bairro;
  var saldoString = "Saldo: " + (contas[indice]).saldo;
  var contaString = "Conta " + (indice + 1);
  var saldoCaixaString = "Saldo no caixa: " + valorCaixa;
  console.log(valorCaixa);
  
  setText("nome_conta", contaString);
  setText("text_area", nomeString + "\n" + sobrenomeString + "\n" + cpfString + "\n" + dataString + "\n" + estadoString + "\n" + cidadeString + "\n" + cepString + "\n" + enderecoString + "\n" + bairroString + "\n" + saldoString);
  
  setText("nome_conta1", contaString);
  setText("text_area1", nomeString + "\n" + sobrenomeString + "\n" + cpfString + "\n" + dataString + "\n" + estadoString + "\n" + cidadeString + "\n" + cepString + "\n" + enderecoString + "\n" + bairroString + "\n" + saldoString);

  setText("nome_conta2", contaString);
  setText("text_area2", nomeString + "\n" + sobrenomeString + "\n" + cpfString + "\n" + dataString + "\n" + estadoString + "\n" + cidadeString + "\n" + cepString + "\n" + enderecoString + "\n" + bairroString + "\n" + saldoString);
  
  setText("text_area3", saldoCaixaString);
  
  
}
function wrap(valor, menor, maior) {
  var output;
  if (valor < menor) {
    output = maior;
  } else if (valor > maior) {
    output = menor;
  } else {
    output = valor;
  }
  return output;
}

//Aqui abastecemos o caixa


onEvent("bot_abastecer", "click", function( ) {
  caixa_quantidade = [5, 5, 5, 5, 5, 5, 5, 5];
  abastecer();
  console.log(valorCaixa);
});


//Aqui iremos fazer o deposito
onEvent("bot_direita1", "click", function( ) {
  indice++;
  indice = wrap(indice, 0, contas.length-1);
  mostrarContaAtual();
});
onEvent("bot_esquerda1", "click", function( ) {
  indice--;
  indice = wrap(indice, 0, contas.length-1);
  mostrarContaAtual();
});
onEvent("bot_depositar", "click", function( ) {
  if (getNumber("text_deposito") < 0) {
    setText("text_deposito", "VALOR INVALIDO");
  } else {
    var valorDeposito = getNumber("text_deposito");
    (contas[indice]).saldo += valorDeposito;
    setText("text_deposito", "");
  }
  mostrarContaAtual();
});

//Aqui iremos fazer o saque
onEvent("bot_direita2", "click", function( ) {
  indice++;
  indice = wrap(indice, 0, contas.length-1);
  mostrarContaAtual();
});
onEvent("bot_esquerda2", "click", function( ) {
  indice--;
  indice = wrap(indice, 0, contas.length-1);
  mostrarContaAtual();
});
onEvent("bot_sacar", "click", function( ) {
  var caixa_total = 0;
  for (var i = 0; i < 8; i++) {
  caixa_total = caixa_total + (notas_valor[i]*caixa_quantidade[i]);
}
  var notas_saque = [0, 0, 0, 0, 0, 0, 0, 0];
  var valorSaque = getNumber("text_saque");
  var aux = valorSaque;
  console.log(valorSaque);
  console.log("message");
  var aux2 = 0;
  if ((getNumber("text_saque") < 0)||(getNumber("text_saque") > contas[indice].saldo)) {
    setText("text_saque", "VALOR INVALIDO");
  } else {
    if (caixa_total>=valorSaque) {
      for (i = 0; i < notas_valor.length; i++) {
        aux2 = parseInt(aux / notas_valor[i]);
        valorSaque = aux;
        if (aux2<=caixa_quantidade[i]) {
          notas_saque[i] = parseInt(valorSaque / notas_valor[i]);
          aux = parseInt(valorSaque % notas_valor[i]);
          caixa_quantidade[i] = caixa_quantidade[i] - notas_saque[i];
          console.log("1");
        } else {
          notas_saque[i] = caixa_quantidade[i];
          aux = parseInt(valorSaque % notas_valor[i] + ((aux2-notas_saque[i])*notas_valor[i]));
          caixa_quantidade[i] = 0;
          console.log("2");
        }
      }
      setText("text_area22", getText("text_area22") + ("Valor do saque: " + getNumber("text_saque")));
      for (i = 0; i < notas_valor.length; i++) {
        if (notas_saque[i]>0) {
          setText("text_area22", (getText("text_area22") + "\n") + (("Quantidae de notas de " + notas_valor[i]) + (": " + notas_saque[i])));
        }
        if (caixa_quantidade[i] == 0) {
          aux3++;
        }
        if (aux3 == notas_valor.length) {
          setText("text_saque", "O caixa precisa ser abastecido!");
          aux3 = 0;
        }
      }
      (contas[indice]).saldo -= getNumber("text_saque");
      valorCaixa = valorCaixa - getNumber("text_saque");
      mostrarContaAtual();
    } else {
      setText("text_area22", "Dinheiro em caixa insuficiente");
    }
    setText("text_saque", "");
    
    
    
    
    
    
    
    
  }
  
});
