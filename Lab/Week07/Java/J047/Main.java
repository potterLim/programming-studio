import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        String noSpaces = MyString.removeSpaces(input);
        System.out.println(noSpaces);

        scanner.close();
    }
}
