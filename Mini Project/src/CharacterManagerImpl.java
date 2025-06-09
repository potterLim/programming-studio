import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CharacterManagerImpl implements ICharacterManager {
    private final List<CharacterBase> characterList = new ArrayList<>();
    private final Scanner scanner = new Scanner(System.in);

    @Override
    public void createCharacter() {

        String name;
        while (true) {
            System.out.print("Enter character name: ");
            name = scanner.nextLine();
            if (findCharacterByName(name) != null) {
                System.out.println("Character name already exists. Please enter a different name.");
            } else {
                break;
            }
        }

        String jobStr;
        System.out.print("Enter job (WARRIOR, MAGE, ARCHER, THIEF): ");
        while (true) {
            jobStr = scanner.nextLine().toUpperCase();
            try {
                Job.valueOf(jobStr);
                break;
            } catch (IllegalArgumentException e) {
                System.out.print("Invalid job. Please enter one of WARRIOR, MAGE, ARCHER, THIEF: ");
            }
        }

        int level;
        System.out.print("Enter level: ");
        while (true) {
            try {
                level = Integer.parseInt(scanner.nextLine());
                if (level < 1) {
                    System.out.print("Level must be at least 1. Please enter again: ");
                } else {
                    break;
                }
            } catch (NumberFormatException e) {
                System.out.print("Invalid input. Please enter a valid level: ");
            }
        }

        Job job = Job.valueOf(jobStr);
        CharacterBase character = createCharacterInstance(name, level, job);

        characterList.add(character);
        System.out.println("Character created successfully.");
    }

    private CharacterBase createCharacterInstance(String name, int level, Job job) {
        switch (job) {
            case WARRIOR:
                return new WarriorCharacter(name, level);
            case MAGE:
                return new MageCharacter(name, level);
            case ARCHER:
                return new ArcherCharacter(name, level);
            case THIEF:
                return new ThiefCharacter(name, level);
            default:
                throw new IllegalArgumentException("Unknown job: " + job);
        }
    }

    @Override
    public void readCharacterList() {
        if (characterList.isEmpty()) {
            System.out.println("No characters found.");
            return;
        }

        System.out.println("======== Character List =========");
        System.out.printf("%-15s %-10s %-5s%n", "Name", "Job", "Level");
        System.out.println("---------------------------------");

        for (CharacterBase c : characterList) {
            c.displaySummary();
        }

        System.out.println("---------------------------------");
    }


    @Override
    public void readCharacterDetail() {
        System.out.print("Enter character name: ");
        String name = scanner.nextLine();

        CharacterBase character = findCharacterByName(name);
        if (character != null) {
            System.out.println("====== Character Details ======");
            character.displayDetails();
        } else {
            System.out.println("Character not found.");
        }
    }

    @Override
    public void updateCharacter() {
        System.out.print("Enter character name to update: ");
        String name = scanner.nextLine();

        CharacterBase character = findCharacterByName(name);
        if (character == null) {
            System.out.println("Character not found.");
            return;
        }

        System.out.print("Enter new level: ");
        int newLevel = Integer.parseInt(scanner.nextLine());

        if (newLevel < 1) {
            System.out.println("Level must be at least 1. Update failed.");
            return;
        }
        character.setLevel(newLevel);

        System.out.println("Character updated successfully.");
    }

    @Override
    public void deleteCharacter() {
        System.out.print("Enter character name to delete: ");
        String name = scanner.nextLine();

        CharacterBase character = findCharacterByName(name);
        if (character != null) {
            characterList.remove(character);
            System.out.println("Character deleted successfully.");
        } else {
            System.out.println("Character not found.");
        }
    }

    @Override
    public void searchCharacter() {
        System.out.print("Enter keyword to search: ");
        String keyword = scanner.nextLine().toLowerCase();

        boolean found = false;
        for (CharacterBase c : characterList) {
            if (c.getName().toLowerCase().contains(keyword)) {
                c.displayDetails();
                found = true;
            }
        }

        if (!found) {
            System.out.println("No matching characters found.");
        }
    }

    @Override
    public void saveToFile() {
        File dataDir = new File("../Data");
        if (!dataDir.exists()) {
            if (dataDir.mkdirs()) {
                System.out.println("Created Data directory.");
            } else {
                System.out.println("Failed to create Data directory.");
                return;
            }
        }

        try (FileWriter writer = new FileWriter("../Data/characters.csv")) {
            for (CharacterBase c : characterList) {
                writer.write(String.format("%s,%s,%d%n", c.getName(), c.getJob(), c.getLevel()));
            }
            System.out.println("Characters saved to CSV file successfully.");
        } catch (IOException e) {
            System.out.println("Failed to save characters: " + e.getMessage());
        }
    }

    @Override
    public void loadFromFile() {
        characterList.clear();

        try (BufferedReader reader = new BufferedReader(new FileReader("../Data/characters.csv"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] tokens = line.split(",");
                if (tokens.length != 3) {
                    continue;
                }

                String name = tokens[0];
                if (!tokens[1].equals("WARRIOR") && !tokens[1].equals("MAGE") && !tokens[1].equals("ARCHER") && !tokens[1].equals("THIEF")) {
                    System.out.println("Invalid job '" + tokens[1] + "' for character '" + name + "'. Skipping.");
                    continue;
                }
                Job job = Job.valueOf(tokens[1]);
                int level = Integer.parseInt(tokens[2]);

                if (findCharacterByName(name) != null) {
                    System.out.println("Character with name '" + name + "' already exists. Skipping.");
                    continue;
                }

                CharacterBase character = createCharacterInstance(name, level, job);
                characterList.add(character);
            }
            System.out.println("Characters loaded from CSV file successfully.");
        } catch (IOException e) {
            System.out.println("Failed to load characters: " + e.getMessage());
        }
    }

    private CharacterBase findCharacterByName(String name) {
        for (CharacterBase c : characterList) {
            if (c.getName().equalsIgnoreCase(name)) {
                return c;
            }
        }
        return null;
    }
}
