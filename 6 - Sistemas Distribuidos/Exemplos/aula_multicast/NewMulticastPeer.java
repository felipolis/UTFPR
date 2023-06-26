/**
 * NewMulticastPeer: Implementa um peer multicast
 * Descricao: Envia mensagens para todos os membros do grupo.
 */

import java.net.*;
import java.io.*;
import javax.swing.JOptionPane;

public class NewMulticastPeer{
	
    /* args[0]: interface de rede */ 
	/* args[1]: ip multicast (entre 224.0.0.0 e 239.255.255.255) */
    public static void main(String args[]){ 
		MulticastSocket s = null;
		InetAddress groupIP = null;
        InetSocketAddress group = null;
		NetworkInterface netIf = null;
		int resp = 0;

		if (args.length !=2) {
			System.err.println("Sintaxe: java NewMulticastPeer netIf multicastIP");
			System.err.println("Exemplo: java NewMulticastPeer eno1 225.1.2.3");
			return;
		}

		try {
			/* interface de rede para o multicast */
			NetworkInterface.getByName(args[0]);

			/* cria um grupo multicast */
			groupIP = InetAddress.getByName(args[1]);
			
			/* grupo do multicast */
			group = new InetSocketAddress(groupIP, 6789);

			/* cria um socket multicast */
			s = new MulticastSocket(6789);

			/* desabilita o recebimento local */
			s.setOption(StandardSocketOptions.IP_MULTICAST_LOOP, false);
			
			/* adiciona-se ao grupo */
			s.joinGroup(group, netIf);
			
			/* cria a thread para receber */
			ReceiveThread receiveThread = new ReceiveThread(s);
			receiveThread.start();
 			
 			do {
				String msg = JOptionPane.showInputDialog("Mensagem?");

				/* cria um datagrama com a msg */
				byte [] m = msg.getBytes();
				DatagramPacket messageOut = new DatagramPacket(m, m.length, groupIP, 6789);
				
				/* envia o datagrama como multicast */
				s.send(messageOut);	
				
				resp = JOptionPane.showConfirmDialog(null, "Nova mensagem?", 
                        "Continuar", JOptionPane.YES_NO_OPTION);
            } while (resp != JOptionPane.NO_OPTION);

   			/* retira-se do grupo */
			s.leaveGroup(group, netIf);		

		}catch (SocketException e){
			System.out.println("Socket: " + e.getMessage());
		}catch (IOException e){
			System.out.println("IO: " + e.getMessage());
		}finally {
			if (s != null) s.close(); //fecha o socket
		} //finally
	} //main		      	
}//class


