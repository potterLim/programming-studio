import java.util.Scanner;

public class J023 {
    public static void main(String[] args) {
        int count;
        int number;
        int totalSum = 0;
        double average;
        Scanner scanner = new Scanner(System.in);

        count = scanner.nextInt();

        for (int i = 0; i < count; ++i) {
            number = scanner.nextInt();
            totalSum += number;
        }

        average = totalSum / (double) count;
        average = Math.round(average * 10.0) / 10.0;

        System.out.println(totalSum + " " + average);
        scanner.close();
    }
}
