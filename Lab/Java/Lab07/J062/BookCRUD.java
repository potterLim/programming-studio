import java.util.ArrayList;
import java.util.Scanner;

public class BookCRUD {
    private ArrayList<Book> books;
    private Scanner scanner;

    public BookCRUD() {
        books = new ArrayList<>();
        scanner = new Scanner(System.in);
    }

    public void addBook() {
        System.out.print("Title > ");
        String title = scanner.nextLine();

        System.out.print("Author > ");
        String author = scanner.nextLine();

        System.out.print("Category > ");
        String category = scanner.nextLine();

        System.out.print("Price > ");
        int price = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Year > ");
        int year = scanner.nextInt();
        scanner.nextLine();

        Book book = new Book(title, author, category, price, year);
        books.add(book);

        System.out.println("Book added.");
    }

    public void editBook() {
        if (books.isEmpty()) {
            System.out.println("No books to edit.");
            return;
        }

        listBook();

        System.out.print("Select number to edit > ");
        int index = scanner.nextInt() - 1;
        scanner.nextLine();

        if (index < 0 || index >= books.size()) {
            System.out.println("Invalid index.");
            return;
        }

        Book book = books.get(index);

        System.out.print("New Title > ");
        String newTitle = scanner.nextLine();
        book.setTitle(newTitle);

        System.out.print("New Author > ");
        String newAuthor = scanner.nextLine();
        book.setAuthor(newAuthor);

        System.out.print("New Category > ");
        String newCategory = scanner.nextLine();
        book.setCategory(newCategory);

        System.out.print("New Price > ");
        int newPrice = scanner.nextInt();
        scanner.nextLine();
        book.setPrice(newPrice);

        System.out.print("New Year > ");
        int newYear = scanner.nextInt();
        scanner.nextLine();
        book.setYear(newYear);

        System.out.println("Book updated.");
    }

    public void listBook() {
        if (books.isEmpty()) {
            System.out.println("No books in the list.");
            return;
        }

        for (int i = 0; i < books.size(); ++i) {
            System.out.printf("%d. %s%n", i + 1, books.get(i).toString());
        }
    }

    public void deleteBook() {
        if (books.isEmpty()) {
            System.out.println("No books to delete.");
            return;
        }

        listBook();

        System.out.print("Select number to delete > ");
        int index = scanner.nextInt() - 1;
        scanner.nextLine();

        if (index < 0 || index >= books.size()) {
            System.out.println("Invalid index.");
            return;
        }

        books.remove(index);

        System.out.println("Book deleted.");
    }
}
