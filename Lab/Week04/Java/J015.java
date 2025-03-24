import java.util.Scanner;

public class J015 {
    public static void main(String[] args) {
        int num1;
        int num2;
        int num3;
        int maxNum;
        int minNum;

        Scanner scanner = new Scanner(System.in);

        num1 = scanner.nextInt();
        num2 = scanner.nextInt();
        num3 = scanner.nextInt();

        if (num1 >= num2 && num1 >= num3) {
            maxNum = num1;
        } else if (num2 >= num1 && num2 >= num3) {
            maxNum = num2;
        } else {
            maxNum = num3;
        }

        if (num1 <= num2 && num1 <= num3) {
            minNum = num1;
        } else if (num2 <= num1 && num2 <= num3) {
            minNum = num2;
        } else {
            minNum = num3;
        }

        System.out.println(maxNum + " " + minNum);

        scanner.close();
    }
}