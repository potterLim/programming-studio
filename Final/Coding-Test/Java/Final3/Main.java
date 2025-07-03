import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        TicketManager manager = new TicketManager();

        System.out.print("Enter number of tickets to input (1-10): ");
        int count = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < count; ++i) {
            System.out.println("Enter ticket #" + (i + 1) + " info:");

            System.out.print("Title: ");
            String title = scanner.nextLine();

            System.out.print("Seat: ");
            String seat = scanner.nextLine();

            System.out.print("Price: ");
            int price = scanner.nextInt();
            scanner.nextLine();

            MovieTicket ticket = new MovieTicket(title, seat, price);
            manager.addTicket(ticket);
        }

        System.out.println("\nTickets sorted by price (descending):");
        manager.printByPriceDescending();

        scanner.close();
    }
}
