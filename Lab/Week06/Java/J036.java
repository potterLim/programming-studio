import java.util.Scanner;

public class J036 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        String onlyAlphabet = "";
        for (int i = 0; i < input.length(); ++i) {
            char ch = input.charAt(i);
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                onlyAlphabet += Character.toLowerCase(ch);
            }
        }

        boolean isPalindrome = true;
        for (int i = 0; i < onlyAlphabet.length() / 2; ++i) {
            if (onlyAlphabet.charAt(i) != onlyAlphabet.charAt(onlyAlphabet.length() - 1 - i)) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        scanner.close();
    }
}
