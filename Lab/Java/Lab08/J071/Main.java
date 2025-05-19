import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        TodoCRUD manager = new TodoCRUD();
        boolean quit = false;

        while (!quit) {
            System.out.print("> ");
            String input = scanner.nextLine().trim();
            if (input.isEmpty()) {
                continue;
            }
            String[] tokens = input.split("\\s+");
            String command = tokens[0];

            switch (command) {
                case "add":
                    manager.addItem();
                    break;

                case "edit":
                    manager.updateItem();
                    break;

                case "del":
                    manager.deleteItem();
                    break;

                case "ls":
                    if (input.contains("name")) {
                        manager.sortByName();
                    }
                    if (input.contains("date")) {
                        manager.sortByDate();
                    }
                    if (input.contains("desc")) {
                        manager.reverseList();
                    }
                    manager.printAll();
                    break;

                case "?":
                    System.out.println("Usage of commands");
                    System.out.println("1. Add a new item ( add )");
                    System.out.println("2. Delete an existing item ( del )");
                    System.out.println("3. Update an item ( edit )");
                    System.out.println("4. List all items ( ls )");
                    System.out.println("5. sort the list by name ( ls name )");
                    System.out.println("6. sort the list by name descending ( ls name desc )");
                    System.out.println("7. sort the list by date ( ls date )");
                    System.out.println("8. sort the list by date descending ( ls date desc )");
                    System.out.println("9. show commands guidelines ( ? )");
                    System.out.println("10. quit program ( exit )");
                    break;

                case "exit":
                    quit = true;
                    break;

                default:
                    System.out.println("? for help.");
                    break;
            }
        }
    }
}