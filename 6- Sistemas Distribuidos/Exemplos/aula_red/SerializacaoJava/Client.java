/*
 *  Learning Project.
 */
package aula_red.SerializacaoJava;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author rodrigo
 */
public class Client {
    public static void main(String[] args) {
        try {
            Person p = new Person("Smith", "London", 1986);
            Socket clientSocket = new Socket(InetAddress.getByName("127.0.0.1"), 5555);
            ObjectOutputStream out = new ObjectOutputStream(clientSocket.getOutputStream());
            out.writeObject(p);
            out.flush();
            System.out.println("Client sends Object Person.");
            clientSocket.close();
        } catch (UnknownHostException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
}
