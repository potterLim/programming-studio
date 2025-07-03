import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Title: ");
        String title = scanner.nextLine();
        System.out.print("Author: ");
        String author = scanner.nextLine();
        System.out.print("Price: ");
        int price = scanner.nextInt();

        Book book = new Book(title, author, price);
        book.setCategory();
        book.printInfo();

        scanner.close();
    }
}