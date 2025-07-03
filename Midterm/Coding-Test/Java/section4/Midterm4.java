import java.util.Scanner;

public class Midterm4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input: ");
        String inputLine = scanner.nextLine();
        String result = inputLine.replaceAll("\\s+", "");

        System.out.println("Output: " + result);

        scanner.close();
    }
}