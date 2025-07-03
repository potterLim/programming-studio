import java.util.Scanner;

public class Midterm2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Input: ");
        double xStart = scanner.nextDouble();
        double yStart = scanner.nextDouble();
        double xEnd = scanner.nextDouble();
        double yEnd = scanner.nextDouble();

        double distance = Math.sqrt(Math.pow(xEnd - xStart, 2) + Math.pow(yEnd - yStart, 2));
        distance = Math.round(distance * 10) / 10.0;

        System.out.println("Output: Distance: " + distance);

        scanner.close();
    }
}