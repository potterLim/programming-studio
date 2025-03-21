import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        double x1;
        double y1;
        double x2;
        double y2;

        Scanner scanner = new Scanner(System.in);
        x1 = scanner.nextDouble();
        y1 = scanner.nextDouble();
        x2 = scanner.nextDouble();
        y2 = scanner.nextDouble();

        double distance = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        distance = Math.round(distance * 10.0) / 10.0;
        System.out.println(distance);

        scanner.close();
    }
}