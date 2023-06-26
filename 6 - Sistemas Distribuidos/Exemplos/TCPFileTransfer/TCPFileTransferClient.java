
import java.io.DataInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.net.Socket;

/***
 *  Learning Project.
 * @author rodrigo
 */
public class TCPFileTransferClient {
    public static void main(String[] args) throws Exception {
        Socket clientSocket = new Socket("localhost", 6666);
        DataInputStream in = new DataInputStream(clientSocket.getInputStream());

        /* PROTOCOLO - START */
        String fileName = in.readUTF();
        File file = new File("resource/copia_" + fileName);
        FileOutputStream outputFile = new FileOutputStream(file);
        
        long sizeFile = in.readLong();
        for (; sizeFile > 0; sizeFile--) {
            byte b = in.readByte();
            outputFile.write(b);
        }
        /* PROTOCOLO - END */
        
        outputFile.close();
        in.close();

        System.out.println("File Size: " + file.length() + "\n");
        System.out.println("File tranfered.");
    }
    
}
