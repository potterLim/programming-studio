import java.util.Scanner;

public class J029 {
    public static void main(String[] args) {
        int[] numbers = new int[10];
        int count = 0;
        boolean[] flag = new boolean[100];
        Scanner scanner = new Scanner(System.in);

        while (true) {
            if (count == 10) {
                break;
            }

            System.out.print("Entry #" + (count + 1) + " number > ");
            numbers[count] = scanner.nextInt();

            if (numbers[count] < 1 || numbers[count] > 100) {
                System.out.println("Out of range. Please enter a number between 1 and 100.");
                continue;
            }

            if (!flag[numbers[count] - 1]) {
                flag[numbers[count] - 1] = true;
                ++count;
            } else {
                System.out.println("Duplicated! Retry.");
            }
        }

        System.out.print("Numbers - ");
        for (int i = 0; i < count; ++i) {
            System.out.print(numbers[i] + " ");
        }

        System.out.println();
        scanner.close();
    }
}
