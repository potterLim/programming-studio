import java.util.Scanner;

public class J024 {
    public static void main(String[] args) {
        int[] numbers = new int[10];
        int first;
        int second;
        int firstMaxIndex;
        int secondMaxIndex;
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 10; ++i) {
            numbers[i] = scanner.nextInt();
        }

        if (numbers[0] > numbers[1]) {
            first = numbers[0];
            second = numbers[1];
            firstMaxIndex = 0;
            secondMaxIndex = 1;
        } else {
            first = numbers[1];
            second = numbers[0];
            firstMaxIndex = 1;
            secondMaxIndex = 0;
        }

        for (int i = 2; i < numbers.length; ++i) {
            if (numbers[i] > first) {
                second = first;
                secondMaxIndex = firstMaxIndex;
                first = numbers[i];
                firstMaxIndex = i;
            } else if (numbers[i] > second && numbers[i] < first) {
                second = numbers[i];
                secondMaxIndex = i;
            }
        }

        System.out.println("[" + (secondMaxIndex + 1) + "] " + numbers[secondMaxIndex]);
        scanner.close();
    }
}
