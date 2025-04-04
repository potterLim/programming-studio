import java.util.Scanner;

public class J028 {
    public static void main(String[] args) {
        int[][] scores = new int[5][3];
        int[] sumStudent = new int[5];
        double[] avgStudent = new double[5];
        char[] grade = new char[5];
        int[] sumClasses = new int[3];
        double[] avgClass = new double[3];
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                scores[i][j] = scanner.nextInt();
                sumStudent[i] += scores[i][j];
                sumClasses[j] += scores[i][j];
            }

            avgStudent[i] = sumStudent[i] / 3.0;

            if (avgStudent[i] >= 90) {
                grade[i] = 'A';
            } else if (avgStudent[i] >= 80) {
                grade[i] = 'B';
            } else if (avgStudent[i] >= 70) {
                grade[i] = 'C';
            } else if (avgStudent[i] >= 60) {
                grade[i] = 'D';
            } else {
                grade[i] = 'F';
            }
        }

        for (int j = 0; j < 3; ++j) {
            avgClass[j] = sumClasses[j] / 5.0;
            avgClass[j] = Math.round(avgClass[j] * 10.0) / 10.0;
        }

        for (int i = 0; i < 5; ++i) {
            avgStudent[i] = Math.round(avgStudent[i] * 10.0) / 10.0;
        }

        System.out.println("Korean - Sum " + sumClasses[0] + ", Average " + avgClass[0]);
        System.out.println("English - Sum " + sumClasses[1] + ", Average " + avgClass[1]);
        System.out.println("Math - Sum " + sumClasses[2] + ", Average " + avgClass[2]);

        for (int i = 0; i < 5; ++i) {
            System.out.println("#" + (i + 1) + " Student - Sum " + sumStudent[i] + ", Average " + avgStudent[i] + ", Grade " + grade[i]);
        }
        scanner.close();
    }
}