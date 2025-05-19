import java.util.ArrayList;
import java.util.Scanner;

public class WordCRUD {
    private ArrayList<Word> words;
    private Scanner scanner;

    public WordCRUD() {
        words = new ArrayList<>();
        scanner = new Scanner(System.in);
    }

    public void addWord() {
        System.out.print("English > ");
        String english = scanner.nextLine();

        System.out.print("Korean > ");
        String korean = scanner.nextLine();

        System.out.print("Level (1~3) > ");
        int level = scanner.nextInt();
        scanner.nextLine();

        Word word = new Word(english, korean, level);
        words.add(word);

        System.out.println("Word added.");
    }

    public void editWord() {
        if (words.isEmpty()) {
            System.out.println("No words to edit.");
            return;
        }

        listWord();

        System.out.print("Select number to edit > ");
        int index = scanner.nextInt() - 1;
        scanner.nextLine();

        if (index < 0 || index >= words.size()) {
            System.out.println("Invalid index.");
            return;
        }

        Word word = words.get(index);

        System.out.print("New English > ");
        String newEnglish = scanner.nextLine();

        System.out.print("New Korean > ");
        String newKorean = scanner.nextLine();

        System.out.print("New Level (1~3) > ");
        int newLevel = scanner.nextInt();
        scanner.nextLine();

        word.setEnglish(newEnglish);
        word.setKorean(newKorean);
        word.setLevel(newLevel);

        System.out.println("Word updated.");
    }

    public void listWord() {
        if (words.isEmpty()) {
            System.out.println("No words in the list.");
            return;
        }

        for (int i = 0; i < words.size(); ++i) {
            System.out.printf("%d. %s%n", i + 1, words.get(i).toString());
        }
    }

    public void deleteWord() {
        if (words.isEmpty()) {
            System.out.println("No words to delete.");
            return;
        }

        listWord();

        System.out.print("Select number to delete > ");
        int index = scanner.nextInt() - 1;
        scanner.nextLine();

        if (index < 0 || index >= words.size()) {
            System.out.println("Invalid index.");
            return;
        }

        words.remove(index);

        System.out.println("Word deleted.");
    }
}
