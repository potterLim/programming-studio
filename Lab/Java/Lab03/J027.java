import java.util.Scanner;

public class J027 {
    public static void main(String[] args) {
        int[] heights = new int[10];
        int[] weights = new int[10];
        double[] bmis = new double[10];
        int[] overweightPersons = new int[10];
        int count = 0;
        int countPersons;
        Scanner scanner = new Scanner(System.in);

        countPersons = scanner.nextInt();

        for (int i = 0; i < countPersons; ++i) {
            heights[i] = scanner.nextInt();
            weights[i] = scanner.nextInt();
            bmis[i] = weights[i] / ((heights[i] / 100.0) * (heights[i] / 100.0));

            if (bmis[i] >= 25) {
                overweightPersons[count] = i;
                ++count;
            }
        }

        System.out.print("Overweight person - ");
        for (int i = 0; i < count; ++i) {
            System.out.print((overweightPersons[i] + 1) + " ");
        }

        System.out.println();
        System.out.println("Total - " + count);
        scanner.close();
    }
}
