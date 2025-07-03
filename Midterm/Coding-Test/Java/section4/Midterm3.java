import java.util.Scanner;

public class Midterm3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] values = new int[10];
        System.out.print("Input: ");
        for (int i = 0; i < values.length; ++i) {
            values[i] = scanner.nextInt();
        }

        int max1 = values[0];
        int max2 = values[1];
        int max1Index = 0;
        int max2Index = 1;
        if (values[0] < values[1]) {
            max1 = values[1];
            max1Index = 1;
            max2 = values[0];
            max2Index = 0;
        }

        for (int i = 2; i < values.length; ++i) {
            if (values[i] > max1) {
                max2 = max1;
                max2Index = max1Index;
                max1 = values[i];
                max1Index = i;
            }
            else if (values[i] > max2 && values[i] < max1) {
                max2 = values[i];
                max2Index = i;
            }
        }

        System.out.println("Output: Second Max: " + max2 + " at index " + max2Index);

        scanner.close();
    }
}