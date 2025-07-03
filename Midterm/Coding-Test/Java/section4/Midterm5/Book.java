public class Book {
    private String title;
    private String author;
    private int price;
    private String category;

    public Book(String title, String author, int price) {
        this.title = title;
        this.author = author;
        this.price = price;
    }

    public void setCategory() {
        if (price >= 30000) {
            this.category = "Expensive";
        }
        else {
            this.category = "Affordable";
        }
    }

    public void printInfo() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: " + price);
        System.out.println("Category: " + category);
    }
}