import java.util.Scanner;

public class J011 {
    public static void main(String[] args) {
        int height;
        int weight;
        double bmi;

        Scanner scanner = new Scanner(System.in);

        height = scanner.nextInt();
        weight = scanner.nextInt();

        bmi = weight / ((height / 100.0) * (height / 100.0));

        if (bmi >= 25) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        scanner.close();
    }
}