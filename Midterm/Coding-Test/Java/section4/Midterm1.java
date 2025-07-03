import java.util.Scanner;

public class Midterm1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input: ");
        double fahrenheit = scanner.nextDouble();

        double celsius = (fahrenheit - 32) / 1.8;
        celsius = Math.round(celsius * 10) / 10.0;

        System.out.println("Output: Celsius: " + celsius);

        scanner.close();
    }
}