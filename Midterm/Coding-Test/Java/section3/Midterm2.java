import java.util.Scanner;

public class Midterm2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input: ");
        String sentence = scanner.nextLine();

        String[] words = sentence.split(" ");
        String longestWord = "";
        for (String word : words) {
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
        }

        System.out.println("Output: Longest Word: " + longestWord + " (Length: " + longestWord.length() + ")");

        scanner.close();
    }
}