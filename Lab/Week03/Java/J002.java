import java.util.Scanner;

public class J002 {
    public static void main(String[] args) {
        double celsius;
        double fahrenheit;

        Scanner scanner = new Scanner(System.in);
        celsius = scanner.nextDouble();

        fahrenheit = celsius * 1.8 + 32;
        fahrenheit = Math.round(fahrenheit * 10.0) / 10.0;
        System.out.println(fahrenheit);

        scanner.close();
    }
}