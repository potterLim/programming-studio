import java.util.Scanner;
import java.util.regex.Pattern;

public class Final2 {
    private static final String[] FORBIDDEN_WORDS = {"바보", "멍청이", "욕설"};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a message: ");
        String message = scanner.nextLine();

        for (String word : FORBIDDEN_WORDS) {
            String pattern = "(?i)" + Pattern.quote(word);
            String mask = "*".repeat(word.length());
            message = message.replaceAll(pattern, mask);
        }

        System.out.println("Filtered message: " + message);

        scanner.close();
    }
}
