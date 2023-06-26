/**
 * MulticastPeer: Implementa um peer multicast
 * Descricao: Envia mensagens para todos os membros do grupo.
 */

import java.net.*;
import java.io.*;
import javax.swing.JOptionPane;

public class MulticastPeer{
	
    public static void main(String args[]){ 
		/* args[0]: ip multicast (entre 224.0.0.0 e 239.255.255.255) */ 
		MulticastSocket s =null;
		InetAddress group = null;
		int resp = 0;
		
		try {
			/* cria um grupo multicast */
			group = InetAddress.getByName(args[0]);
			
			/* cria um socket multicast */
			s = new MulticastSocket(6789);

			/* desabilita o recebimento local */
			s.setLoopbackMode(true);
			
			/* adiciona-se ao grupo */
			s.joinGroup(group);
			
			/* cria a thread para receber */
			ReceiveThread receiveThread = new ReceiveThread(s);
			receiveThread.start();
 			
 			do {
				String msg = JOptionPane.showInputDialog("Mensagem?");

				/* cria um datagrama com a msg */
				byte [] m = msg.getBytes();
				DatagramPacket messageOut = new DatagramPacket(m, m.length, group, 6789);
				
				/* envia o datagrama como multicast */
				s.send(messageOut);	
				
				resp = JOptionPane.showConfirmDialog(null, "Nova mensagem?", 
                        "Continuar", JOptionPane.YES_NO_OPTION);
            } while (resp != JOptionPane.NO_OPTION);

   			/* retira-se do grupo */
			s.leaveGroup(group);		
		}catch (SocketException e){
			System.out.println("Socket: " + e.getMessage());
		}catch (IOException e){
			System.out.println("IO: " + e.getMessage());
		}finally {
			if (s != null) s.close(); //fecha o socket
		} //finally
	} //main		      	
}//class

