import java.io.*;
import java.net.*;

class ReceiveThread extends Thread {
	MulticastSocket multicastSocket = null;
	
	public ReceiveThread (MulticastSocket multicastSocket) {
			this.multicastSocket = multicastSocket;
	}
	
	public void run() {
		try {
			while (true) {
				byte[] buffer = new byte[1000];
				DatagramPacket messageIn = new DatagramPacket(buffer, buffer.length);
				multicastSocket.receive(messageIn);
				System.out.println("Recebido:" + new String(messageIn.getData(),0,messageIn.getLength()));
			}
 		} catch (Exception e) {
			System.out.println(e);
		}
  	
	}
}
