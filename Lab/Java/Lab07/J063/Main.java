import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        TodoCRUD manager = new TodoCRUD();

        while (true) {
            System.out.println("\nMenu > 1. Add 2. Edit 3. List 4. Delete 0. Exit");
            System.out.print("Select > ");
            int menu = scanner.nextInt();
            scanner.nextLine();

            switch (menu) {
                case 1: 
                    manager.addTodo();
                    break;
                case 2: 
                    manager.editTodo();
                    break;
                case 3: 
                    manager.listTodo();
                    break;
                case 4: 
                    manager.deleteTodo();
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
