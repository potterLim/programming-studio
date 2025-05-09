import java.util.Scanner;

public class BMICalculator {
    private double heightCm;
    private double weightKg;
    private double bmi;
    private int bmiGrade;
    private String userName;

    public BMICalculator() {
    }

    public void readUserData() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter name: ");
        this.userName = scanner.nextLine();
        System.out.print("Enter height (cm): ");
        this.heightCm = scanner.nextDouble();
        System.out.print("Enter weight (kg): ");
        this.weightKg = scanner.nextDouble();

        double heightMeters = this.heightCm / 100.0;
        this.bmi = this.weightKg / (heightMeters * heightMeters);

        if (this.bmi >= 30.0) {
            this.bmiGrade = 4;
        } else if (this.bmi >= 25.0) {
            this.bmiGrade = 3;
        } else if (this.bmi >= 18.5) {
            this.bmiGrade = 2;
        } else {
            this.bmiGrade = 1;
        }
    }

    public void displayBmi() {
        System.out.printf("Name: %s%n", this.userName);
        System.out.printf("Height: %.2f cm%n", this.heightCm);
        System.out.printf("Weight: %.2f kg%n", this.weightKg);
        System.out.printf("BMI: %.2f%n", this.bmi);

        String gradeDescription;
        switch (this.bmiGrade) {
            case 1: {
                gradeDescription = "Underweight";
                break;
            }
            case 2: {
                gradeDescription = "Healthy Weight";
                break;
            }
            case 3: {
                gradeDescription = "Overweight";
                break;
            }
            case 4: {
                gradeDescription = "Obesity";
                break;
            }
            default: {
                gradeDescription = "Unknown";
                break;
            }
        }

        System.out.printf("BMI Grade: %d (%s)%n", this.bmiGrade, gradeDescription);
    }
}
