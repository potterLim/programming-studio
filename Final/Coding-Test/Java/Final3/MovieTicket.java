public class MovieTicket {
    private final String title;
    private final String seat;
    private final int price;

    public MovieTicket(String title, String seat, int price) {
        this.title = title;
        this.seat = seat;
        this.price = price;
    }

    public String getTitle() {
        return this.title;
    }

    public String getSeat() {
        return this.seat;
    }

    public int getPrice() {
        return this.price;
    }
}
