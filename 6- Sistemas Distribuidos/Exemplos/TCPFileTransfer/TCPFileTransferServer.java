
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;

/**
 * Learning Project.
 * @author rodrigo
 */
public class TCPFileTransferServer {
    public static void main(String[] args) throws Exception {

        System.out.println("Starting server...");
        ServerSocket serverSocket = new ServerSocket(6666);
        Socket clientSocket = serverSocket.accept();
        DataOutputStream out = new DataOutputStream(clientSocket.getOutputStream());
        
        File dir = new File("resource");
        String[] listFiles = dir.list();
        String fileName = listFiles[new Random().nextInt(listFiles.length)];
        
        File file = new File("resource/" + fileName);
        FileInputStream inputFile = new FileInputStream(file);
        
        /* PROTOCOLO - START */
        System.out.println("Transfering file " + fileName);
        out.writeUTF(fileName);
        out.writeLong(file.length());
        int byteFromFile;
        while ((byteFromFile = inputFile.read()) != -1) {
            out.writeByte(byteFromFile);
        }
       /* PROTOCOLO - END */

        inputFile.close();
        out.close();
        System.out.println("File Size: " + file.length() + "\n");
        System.out.println("File transfer finished.\n");
    }
    
}
