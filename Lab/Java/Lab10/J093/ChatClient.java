import java.net.Socket;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.PrintWriter;

public class ChatClient {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println(
                "Usage: java ChatClient <username> <server ip>"
            );
            System.exit(1);
        }

        String userName = args[0];
        String serverIp = args[1];

        try {
            Socket socket = new Socket(serverIp, 10001);
            PrintWriter writer = new PrintWriter(
                new OutputStreamWriter(socket.getOutputStream())
            );
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(socket.getInputStream())
            );
            BufferedReader keyboard = new BufferedReader(
                new InputStreamReader(System.in)
            );

            Thread readerThread = new Thread() {
                @Override
                public void run() {
                    try {
                        String serverMessage = null;
                        while ((serverMessage = reader.readLine()) != null) {
                            System.out.println(serverMessage);
                        }
                    } catch (Exception e) {
                        System.out.println(e);
                    }
                }
            };
            readerThread.start();

            String userInput = null;
            while ((userInput = keyboard.readLine()) != null) {
                String fullMessage = userName + " : " + userInput;
                writer.println(fullMessage);
                writer.flush();
                if (userInput.equals("/quit")) {
                    break;
                }
            }
            socket.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}