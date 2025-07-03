import java.util.Scanner;

public class Midterm5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input: ");
        String input = scanner.nextLine();
    
        String filteredText = input.replaceAll("[^a-zA-Z]", "").toLowerCase();
        String reversedText = new StringBuilder(filteredText).reverse().toString();
    
        if (filteredText.equals(reversedText)) {
            System.out.println("Output: Yes");
        } else {
            System.out.println("Output: No");
        }

        scanner.close();
    }
}