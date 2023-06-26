/**
 * UDPServer: Servidor UDP
 * Descricao: Recebe um datagrama de um cliente, imprime o conteudo e retorna o mesmo
 * datagrama ao cliente
 */

import java.net.*;
import java.io.*;

public class UDPServer{
    public static void main(String args[]){ 
    	DatagramSocket aSocket = null;
        try{
            aSocket = new DatagramSocket(6666); // cria um socket datagrama em uma porta especifica
            
            while(true){
                byte[] buffer = new byte[1000]; // cria um buffer para receber requisições

		/* cria um pacote vazio */
                DatagramPacket request = new DatagramPacket(buffer, buffer.length);
                aSocket.receive(request);  // aguarda a chegada de datagramas

		/* imprime e envia o datagrama de volta ao cliente */
		System.out.println("Cliente: " + new String(request.getData()));    
                DatagramPacket reply = new DatagramPacket(request.getData(), request.getLength(), request.getAddress(), request.getPort()); // cria um pacote com os dados

                aSocket.send(reply); // envia o pacote
            } //while
        }catch (SocketException e){
	   System.out.println("Socket: " + e.getMessage());
        }catch (IOException e) {
	   System.out.println("IO: " + e.getMessage());
        } //catch
    } //main
}//class
