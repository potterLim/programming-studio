import java.net.ServerSocket;
import java.net.Socket;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.List;
import java.util.ArrayList;

public class ChatServer {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(10001);
            List<PrintWriter> clientWriters = new ArrayList<PrintWriter>();

            while (true) {
                Socket socket = serverSocket.accept();
                new ClientHandler(socket, clientWriters).start();
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

class ClientHandler extends Thread {
    private Socket socket;
    private List<PrintWriter> clientWriters;
    private BufferedReader reader;
    private PrintWriter writer;

    public ClientHandler(Socket socket, List<PrintWriter> clientWriters) {
        this.socket = socket;
        this.clientWriters = clientWriters;
        try {
            reader = new BufferedReader(
                new InputStreamReader(socket.getInputStream())
            );
            writer = new PrintWriter(
                new OutputStreamWriter(socket.getOutputStream())
            );
            synchronized (clientWriters) {
                clientWriters.add(writer);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    @Override
    public void run() {
        try {
            String message = null;
            while ((message = reader.readLine()) != null) {
                synchronized (clientWriters) {
                    for (int i = 0; i < clientWriters.size(); ++i) {
                        PrintWriter pw = clientWriters.get(i);
                        if (pw != writer) {
                            pw.println(message);
                            pw.flush();
                        }
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            synchronized (clientWriters) {
                clientWriters.remove(writer);
            }
            try {
                socket.close();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}