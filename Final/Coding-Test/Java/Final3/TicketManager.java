import java.util.Arrays;
import java.util.Comparator;

public class TicketManager {
    private static final int MAX_TICKETS = 10;
    private final MovieTicket[] tickets;
    private int count;

    public TicketManager() {
        this.tickets = new MovieTicket[MAX_TICKETS];
        this.count = 0;
    }

    public void addTicket(MovieTicket ticket) {
        if (this.count >= MAX_TICKETS) {
            System.out.println("Cannot add more tickets.");
            return;
        }

        this.tickets[this.count] = ticket;
        ++this.count;
    }

    public void printByPriceDescending() {
        MovieTicket[] sorted = Arrays.copyOf(this.tickets, this.count);

        Arrays.sort(sorted, new Comparator<MovieTicket>() {
            @Override
            public int compare(MovieTicket a, MovieTicket b) {
                return b.getPrice() - a.getPrice();
            }
        });

        for (MovieTicket ticket : sorted) {
            System.out.printf("%s %s ₩%d%n", ticket.getTitle(), ticket.getSeat(), ticket.getPrice());

        }
    }
}
