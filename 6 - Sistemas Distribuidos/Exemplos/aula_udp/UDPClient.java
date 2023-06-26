package aula_udp;

/**
 * UDPClient: Cliente UDP Descricao: Envia uma msg em um datagrama e recebe a
 * mesma msg do servidor
 */
import java.net.*;
import java.io.*;
import javax.swing.JOptionPane;

public class UDPClient {

    public static void main(String args[]) {
        DatagramSocket dgramSocket;
        int resp = 0;

        try {
            dgramSocket = new DatagramSocket(); //cria um socket datagrama
            
            String dstIP = JOptionPane.showInputDialog("IP Destino?");
            int dstPort = Integer.parseInt(JOptionPane.showInputDialog("Porta Destino?"));
            
            /* armazena o IP do destino */
            InetAddress serverAddr = InetAddress.getByName(dstIP);
            int serverPort = dstPort; // porta do servidor

            do {
                String msg = JOptionPane.showInputDialog("Mensagem?");

                byte[] m = msg.getBytes(); // transforma a mensagem em bytes

                /* cria um pacote datagrama */
                DatagramPacket request
                        = new DatagramPacket(m, m.length, serverAddr, serverPort);

                /* envia o pacote */
                dgramSocket.send(request);

                /* cria um buffer vazio para receber datagramas */
                byte[] buffer = new byte[1000];
                DatagramPacket reply = new DatagramPacket(buffer, buffer.length);

                /* aguarda datagramas */
                dgramSocket.receive(reply);
                System.out.println("Resposta: " + new String(reply.getData(),0,reply.getLength()));

                resp = JOptionPane.showConfirmDialog(null, "Nova mensagem?", 
                        "Continuar", JOptionPane.YES_NO_OPTION);

            } while (resp != JOptionPane.NO_OPTION);

            /* libera o socket */
            dgramSocket.close();
        } catch (SocketException e) {
            System.out.println("Socket: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("IO: " + e.getMessage());
        } //catch
    } //main		      	
} //class
