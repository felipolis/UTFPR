/**
 * Server App - Exemplo de chat simples com websockets
 * Autor: Campiolo
 * Data: 19/09/2022
 */

package websocketchat;

import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.concurrent.ConcurrentHashMap;

import javax.websocket.EncodeException;
import javax.websocket.OnClose;
import javax.websocket.OnError;
import javax.websocket.OnMessage;
import javax.websocket.OnOpen;
import javax.websocket.Session;
import javax.websocket.server.PathParam;
import javax.websocket.server.ServerEndpoint;


@ServerEndpoint(value = "/chat/{username}", decoders = MessageDecoder.class, encoders = MessageEncoder.class)
public class ChatEndpoint {
    private Session session;   /* representa comunicação entre dois pontos web sockets */
    private String username;   /* nome do usuario do chat */
    
    /* mapa (username, endpoint) */
    private static final ConcurrentHashMap<String, ChatEndpoint> usersMap = new ConcurrentHashMap<>();

    /** executa ao abrir o websocket */
    @OnOpen
    public void onOpen(Session session, @PathParam("username") String username) throws IOException, EncodeException {
        /* envia a lista de usuarios conectados - nao trata concorrencia */
        if (usersMap.size() > 0) {
            String users = Arrays.toString(Collections.list(usersMap.keys()).toArray());
            Message m = new Message();
            m.setContent(users);
            m.setType(Message.MessageType.USERSLIST);
            session.getBasicRemote().sendObject(m);
        }
        
        this.session = session;
        this.username = username;
        usersMap.put(username, this);

        /* envia a todos uma mensagem de JOIN */
        Message message = new Message();
        message.setType(Message.MessageType.JOIN);
        message.setFrom(username);
        message.setContent("conectou.");
        broadcast(message);
    }

    /** executa ao receber uma mensagem */
    @OnMessage
    public void onMessage(Session session, Message message) throws IOException, EncodeException {
        message.setFrom(username);
        
        if (message.getTo().equals("TODOS")) {  /* msg broadcast */
            message.setType(Message.MessageType.SENDALL);
            broadcast(message);
        } else {  /* msg unicast */
            message.setType(Message.MessageType.SENDIDV);
            usersMap.get(message.getTo()).session.getBasicRemote().sendObject(message);
            // send message to owner - not best solution
            this.session.getBasicRemote().sendObject(message);          
        }
    }

    /** executa ao fechar o websocket */
    @OnClose
    public void onClose(Session session) throws IOException, EncodeException {
        usersMap.remove(username);
        Message message = new Message();
        message.setFrom(username);
        message.setContent("desconectou");
        message.setType(Message.MessageType.LEAVE);
        broadcast(message);
    }

    @OnError
    public void onError(Session session, Throwable throwable) {
        // error handling
    }

    private static void broadcast(Message message) throws IOException, EncodeException {
        usersMap.values().forEach(endpoint -> {
            try {
                endpoint.session.getBasicRemote().sendObject(message);
            } catch (IOException | EncodeException e) {
                    e.printStackTrace();
            }
        });
    }

}
