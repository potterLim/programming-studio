import java.util.Scanner;

public class Midterm1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter height (cm): ");
        double heightCm = scanner.nextDouble();
        System.out.print("Enter weight (kg): ");
        double weightKg = scanner.nextDouble();

        double heightM = heightCm / 100.0;
        double bmi = weightKg / (heightM * heightM);
        System.out.printf("Output: BMI: %.2f%n", bmi);

        if (bmi >= 30.0) {
            System.out.println("Obesity");
        } else if (bmi >= 25.0) {
            System.out.println("Overweight");
        } else if (bmi >= 18.5) {
            System.out.println("Normal");
        } else {
            System.out.println("Underweight");
        }

        scanner.close();
    }
}