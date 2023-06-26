/*
 *  Learning Project.
 */
package aula_red.SerializacaoJava;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author rodrigo
 */
public class Server {

    public static void main(String[] args) throws ClassNotFoundException {
        Person p = null;

        try {
            ServerSocket serverSocket = new ServerSocket(5555);
            System.out.println("Server running....");
            while (true) {
                Socket clientSocket = serverSocket.accept();
                ObjectInputStream in = new ObjectInputStream(clientSocket.getInputStream());
                p = (Person) in.readObject();
                System.out.println("Lido: " + p);
                clientSocket.close();
            }
        } catch (IOException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
