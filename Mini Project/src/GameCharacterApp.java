import java.util.Scanner;

public class GameCharacterApp {
    public static void main(String[] args) {
        ICharacterManager manager = new CharacterManagerImpl();
        Scanner scanner = new Scanner(System.in);

        manager.loadFromFile();

        int choice;
        while (true) {
            System.out.println();
            System.out.println("=== Game Character Manager ===");
            System.out.println("1. Create Character");
            System.out.println("2. List All Characters");
            System.out.println("3. View Character Details");
            System.out.println("4. Update Character Level");
            System.out.println("5. Delete Character");
            System.out.println("6. Search Character by Name");
            System.out.println("7. Save Characters to File");
            System.out.println("8. Exit");
            System.out.print("Select> ");
            choice = Integer.parseInt(scanner.nextLine());

            switch (choice) {
                case 1:
                    manager.createCharacter();
                    break;
                case 2:
                    manager.readCharacterList();
                    break;
                case 3:
                    manager.readCharacterDetail();
                    break;
                case 4:
                    manager.updateCharacter();
                    break;
                case 5:
                    manager.deleteCharacter();
                    break;
                case 6:
                    manager.searchCharacter();
                    break;
                case 7:
                    manager.saveToFile();
                    break;
                case 8:
                    System.out.println("Exiting program.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice.");
                    break;
            }
        }
    }
}