import java.util.Scanner;

public class J025 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] monthDays = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int month;
        int day;
        int dayCount = 0;

        month = scanner.nextInt();
        day = scanner.nextInt();

        if (month < 1 || month > 12) {
            System.out.println("Wrong date!");
            scanner.close();
            return;
        }

        if (day < 1 || day > monthDays[month - 1]) {
            System.out.println("Wrong date!");
            scanner.close();
            return;
        }

        for (int i = 0; i < month - 1; ++i) {
            dayCount += monthDays[i];
        }

        dayCount += day;
        System.out.println(dayCount);
        scanner.close();
    }
}
