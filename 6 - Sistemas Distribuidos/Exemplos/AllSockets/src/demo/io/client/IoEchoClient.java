package demo.io.client;

import demo.common.Demo;

import java.io.*;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class IoEchoClient extends Demo {

    public static void main(String[] args) throws IOException {
        BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
        String message;
        while ((message = stdIn.readLine()) != null) {
            Socket socket = new Socket("localhost", 7000);
            logger.info("Echo client started: {}", socket);

            InputStream inputStream = socket.getInputStream();
            OutputStream outputStream = socket.getOutputStream();

            byte[] buffer = message.getBytes();
            outputStream.write(buffer);

            int totalRead = 0;
            while (totalRead < buffer.length) {
                int read = inputStream.read(buffer, totalRead, buffer.length - totalRead);
                if (read <= 0)
                    break;

                totalRead += read;
                logger.info("Echo client read: {} byte(s)", read);
            }

            logger.info("Echo client received: {}", new String(buffer, StandardCharsets.UTF_8));

            socket.close();
            logger.info("Echo client disconnected");
        }
    }
}