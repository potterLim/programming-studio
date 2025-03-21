import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int month;
        int day;
        int dayCount;
        int[] monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        Scanner scanner = new Scanner(System.in);
        month = scanner.nextInt();
        day = scanner.nextInt();

        dayCount = 0;
        for (int i = 0; i < month - 1; i++) {
            dayCount += monthDays[i];
        }
        dayCount += day;
        System.out.println(dayCount);
        
        scanner.close();
    }
}