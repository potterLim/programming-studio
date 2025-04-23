import java.util.Scanner;

public class J022 {
    public static void main(String[] args) {
        double m2Area;
        double pyungArea;
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int count4 = 0;
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 10; ++i) {
            m2Area = scanner.nextDouble();
            pyungArea = m2Area / 3.305;

            if (pyungArea >= 50) {
                ++count4;
            } else if (pyungArea >= 30) {
                ++count3;
            } else if (pyungArea >= 15) {
                ++count2;
            } else {
                ++count1;
            }
        }

        System.out.println("small - " + count1);
        System.out.println("normal - " + count2);
        System.out.println("large - " + count3);
        System.out.println("huge - " + count4);
        scanner.close();
    }
}
