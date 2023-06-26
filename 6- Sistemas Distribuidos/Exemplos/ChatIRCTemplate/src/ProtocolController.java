
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.HashMap;
import java.util.Properties;

/**
 * Gerencia o protocolo e o processamento das mensagens
 * @author rodrigo
 */
public class ProtocolController {

    private final MulticastSocket multicastSocket;
    private final DatagramSocket udpSocket;
    private final InetAddress group;
    private final Integer mport, uport;
    private final String nick;
    private final HashMap<String, InetAddress> onlineUsers;
    private final UIControl ui;

    public ProtocolController(Properties properties) throws IOException {
        mport = (Integer) properties.get("multicastPort");
        uport = (Integer) properties.get("udpPort");
        group = (InetAddress) properties.get("multicastIP");
        nick = (String) properties.get("nickname");
        ui = (UIControl) properties.get("UI");

        multicastSocket = new MulticastSocket(mport);
        udpSocket = new DatagramSocket(uport);
        
        onlineUsers = new HashMap<>();
        onlineUsers.put("Todos", group);  
    }

    public void send(String targetUser, String msg) throws IOException {
    }

    private void sendMessageGroup(Message msg) throws IOException {
    }

    private void sendMessage(Message msg, InetAddress target) throws IOException {
    }

    public void join() throws IOException {
    }

    public void leave() throws IOException {
    }
    
    public void close() throws IOException {
        if (udpSocket != null) udpSocket.close();
        if (multicastSocket != null) multicastSocket.close();
    }

    public void processPacket(DatagramPacket p) throws IOException {
    }

    public void receiveMulticastPacket() throws IOException {
    }

    public void receiveUdpPacket() throws IOException {
    }
}
