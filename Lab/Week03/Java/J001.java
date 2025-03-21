import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int height;
        int weight;
        double bmi;

        Scanner scanner = new Scanner(System.in);
        height = scanner.nextInt();
        weight = scanner.nextInt();

        bmi = weight / ((height / 100.0) * (height / 100.0));
        bmi = Math.round(bmi * 10.0) / 10.0;
        System.out.println(bmi);

        scanner.close();
    }
}