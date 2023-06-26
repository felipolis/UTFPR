/**
 * UDPClient: Cliente UDP
 * Descricao: Envia uma msg em um datagrama e recebe a mesma msg do servidor
 */

import java.net.*;
import java.io.*;

public class UDPClient{
    public static void main(String args[]){ 
        /* args[0]: mensagem  e args[1]: ip destino */
        DatagramSocket aSocket = null;   

        try {
            aSocket = new DatagramSocket(); //cria um socket datagrama
            
            byte[] m = args[0].getBytes(); // transforma a mensagem em bytes
            
            /* armazena o IP do destino */
            InetAddress aHost = InetAddress.getByName(args[1]); 
            int serverPort = 6666; // porta do servidor
            
            /* cria um pacote datagrama */
            DatagramPacket request =
                    new DatagramPacket(m,  args[0].length(), aHost, serverPort);
            
            /* envia o pacote */
            aSocket.send(request);			                        
            
            /* cria um buffer vazio para receber datagramas */
            byte[] buffer = new byte[1000];
            DatagramPacket reply = new DatagramPacket(buffer, buffer.length);	
            
            /* aguarda datagramas */
            aSocket.receive(reply);
            System.out.println("Resposta: " + new String(reply.getData()));

	    /* libera o socket */
	    aSocket.close();	
        } catch (SocketException e){
	    System.out.println("Socket: " + e.getMessage());
        }catch (IOException e){
	    System.out.println("IO: " + e.getMessage());
        } //catch
    } //main		      	
} //class
