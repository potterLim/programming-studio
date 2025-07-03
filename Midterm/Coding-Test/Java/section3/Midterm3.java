import java.util.Scanner;

public class Midterm3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double[] squareMeters = new double[5];
        int countSmall = 0;
        int countNormal = 0;
        int countLarge = 0;
        int countHuge = 0;
        double totalPyeong = 0.0;

        System.out.println("Input: ");
        for (int i = 0; i < squareMeters.length; ++i) {
            squareMeters[i] = scanner.nextDouble();
            double pyeong = squareMeters[i] / 3.305;
            totalPyeong += pyeong;

            if (pyeong >= 50) {
                ++countHuge;
            } else if (pyeong >= 30) {
                ++countLarge;
            } else if (pyeong >= 15) {
                ++countNormal;
            } else {
                ++countSmall;
            }
        }


        System.out.println("Output: ");
        System.out.println("Small - " + countSmall);
        System.out.println("Normal - " + countNormal);
        System.out.println("Large - " + countLarge);
        System.out.println("Huge - " + countHuge);
        System.out.printf("Average Pyeong: %.1f%n", totalPyeong / 5.0);

        scanner.close();
    }
}