import java.util.Scanner;

public class J026 {
    public static void main(String[] args) {
        int number;
        int maxNum;
        int minNum;
        int countNum;
        Scanner scanner = new Scanner(System.in);

        countNum = scanner.nextInt();
        number = scanner.nextInt();
        maxNum = number;
        minNum = number;

        for (int i = 1; i < countNum; ++i) {
            number = scanner.nextInt();

            if (number > maxNum) {
                maxNum = number;
            }

            if (number < minNum) {
                minNum = number;
            }
        }

        System.out.println("가장 큰 수 " + maxNum);
        System.out.println("가장 작은 수 " + minNum);
        scanner.close();
    }
}
