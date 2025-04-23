import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        String longestWord = MyString.findLongestWord(input);
        System.out.println(longestWord + " " + longestWord.length());

        scanner.close();
    }
}
