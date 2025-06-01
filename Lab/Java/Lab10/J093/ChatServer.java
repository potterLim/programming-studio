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
            List<String> clientNames = new ArrayList<String>();
            while (true) {
                Socket socket = serverSocket.accept();
                new ClientHandler(socket, clientWriters, clientNames).start();
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

class ClientHandler extends Thread {
    private Socket socket;
    private List<PrintWriter> clientWriters;
    private List<String> clientNames;
    private BufferedReader reader;
    private PrintWriter writer;
    private String clientName;

    public ClientHandler(Socket socket, List<PrintWriter> clientWriters, List<String> clientNames) {
        this.socket = socket;
        this.clientWriters = clientWriters;
        this.clientNames = clientNames;
        this.clientName = null;
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
                String[] parts = message.split(" : ", 2);
                if (parts.length == 2) {
                    String sender = parts[0];
                    String content = parts[1];
                    if (clientName == null) {
                        clientName = sender;
                        synchronized (clientNames) {
                            clientNames.add(clientName);
                        }
                    }
                    if (content.equals("/userlist")) {
                        StringBuilder listMessage = new StringBuilder();
                        synchronized (clientNames) {
                            listMessage.append("There are ").append(clientNames.size()).append(" users. ");
                            for (int i = 0; i < clientNames.size(); ++i) {
                                listMessage.append(clientNames.get(i));
                                if (i < clientNames.size() - 1) {
                                    listMessage.append(", ");
                                }
                            }
                        }
                        writer.println(listMessage.toString());
                        writer.flush();
                    } else {
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
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            synchronized (clientWriters) {
                clientWriters.remove(writer);
            }
            synchronized (clientNames) {
                if (clientName != null) {
                    clientNames.remove(clientName);
                }
            }
            try {
                socket.close();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}