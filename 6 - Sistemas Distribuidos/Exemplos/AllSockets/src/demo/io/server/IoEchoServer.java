package demo.io.server;

import demo.common.Demo;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class IoEchoServer extends Demo {

    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(7000);
        logger.info("Echo server started: {}", serverSocket);

        boolean active = true;
        while (active) {
            Socket socket = serverSocket.accept(); // blocking
            logger.info("Connection accepted: {}", socket);

            InputStream inputStream = socket.getInputStream();
            OutputStream outputStream = socket.getOutputStream();

            int read;
            byte[] bytes = new byte[1024];
            while ((read = inputStream.read(bytes)) != -1) { // blocking
                logger.info("Echo server read: {} byte(s)", read);

                String message = new String(bytes, 0, read, StandardCharsets.UTF_8);
                logger.info("Echo server received: {}", message);
                if (message.trim().equals("bye")) {
                    active = false;
                }

                outputStream.write(bytes, 0, read); // blocking
            }

            socket.close();
            logger.info("Connection closed");
        }

        serverSocket.close();
        logger.info("Echo server finished");
    }
}
