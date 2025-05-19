import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BookCRUD manager = new BookCRUD();

        while (true) {
            System.out.println("\nMenu > 1. Add 2. Edit 3. List 4. Delete 0. Exit");
            System.out.print("Select > ");
            int menu = scanner.nextInt();
            scanner.nextLine();

            switch (menu) {
                case 1: 
                    manager.addBook();
                    break;
                case 2: 
                    manager.editBook();
                    break;
                case 3: 
                    manager.listBook();
                    break;
                case 4: 
                    manager.deleteBook();
                    break;
                case 0: 
                    System.out.println("Bye!");
                    return;
                default: 
                    System.out.println("Invalid menu.");
                    break;
            }
        }
    }
}
