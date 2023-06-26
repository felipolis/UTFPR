/**
 * Codigo javascript para enviar e receber mensagens de um chat simples.
 * Exemplo basico de aula Web Sockets
 * Autor: Campiolo
 * Data: 19/09/2022
 * @type WebSocket
 */
var ws;

/** Evento ao clicar em Connect */
function connect() {
    var username = document.getElementById("username").value;
    var host = document.location.host;
    var pathname = document.location.pathname;

    /* conectar ao websocket no servidor */
    ws = new WebSocket("ws://" + host + pathname + "chat/" + username);

    /* associa funcao para tratar das mensagens */
    ws.onmessage = function(event) {
        processMessage(event);
    };
};

/** Evento ao clicar em Send */
function send() {
    var content = document.getElementById("msg").value;
    var usersList = document.getElementById("usersList");
    var to = usersList.options[usersList.selectedIndex].value;
    var json = JSON.stringify({
        "content":content,
        "to": to
    });

    ws.send(json);
}

/** Evento ao clicar em Disconnect */
function disconnect() {
    ws.close();
    
    // limpa os usuarios do chat
    var usersList = document.getElementById("usersList");
    for (i = usersList.options.length - 1; i >= 1; i--) usersList.remove(i);
}

/** Processa a mensagem recebida segundo o seu tipo */
function processMessage() {
    var msgArea = document.getElementById("msgarea");
        console.log(event.data);
        var message = JSON.parse(event.data);
        
    switch (message.type.trim()) {
     case "JOIN":    
        var usersList = document.getElementById("usersList");
        var opt = document.createElement('option');
        opt.value = message.from;
        opt.innerHTML = message.from;
        usersList.appendChild(opt);
        msgArea.innerHTML += "++ " + message.from + " : " + message.content + "\n";
        break;
     case "LEAVE": 
        var usersList = document.getElementById("usersList");
        for (var i=0; i<usersList.length; i++) {
            if (usersList.options[i].value === message.from)
                usersList.remove(i);
        }
        msgArea.innerHTML += "-- " + message.from + " : " + message.content + "\n";
        break;
     case "USERSLIST": 
        var usersList = document.getElementById("usersList");
        var array = message.content.substring(1,message.content.length-1).split(",");
        for (i=0; i<array.length; i++) {
            var opt = document.createElement('option');
            opt.value = array[i].trim();
            opt.innerHTML = array[i].trim();
            usersList.appendChild(opt);
        }
        break;
     case "SENDIDV":
        msgArea.innerHTML += message.from + " [" + message.to + "]: " + message.content + "\n";
        break;
     case "SENDALL":
        msgArea.innerHTML += message.from + " [TODOS]: " + message.content + "\n";       
    }
    
    /* move a barra de rolagem para o final */
    msgArea.scrollTop = msgArea.scrollHeight;
}