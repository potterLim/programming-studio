import java.util.Scanner;

public class J030 {
    public static void main(String[] args) {
        String[] names = { "James", "David", "Simon", "Peter", "Jason" };
        int[][] sheet = new int[5][10];
        int[] answer = { 1, 2, 3, 4, 1, 2, 3, 4, 3, 2 };
        int[] grade = new int[5];
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 10; ++j) {
                sheet[i][j] = scanner.nextInt();
            }
        }

        int[] score = new int[5];
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (sheet[i][j] == answer[j]) {
                    ++score[i];
                }
            }
        }

        int[] countGrades = new int[3];
        for (int i = 0; i < 5; ++i) {
            if (score[i] >= 9) {
                grade[i] = 1;
                ++countGrades[0];
            } else if (score[i] >= 7) {
                grade[i] = 2;
                ++countGrades[1];
            } else {
                grade[i] = 3;
                ++countGrades[2];
            }
        }

        System.out.print("1st : ");
        for (int i = 0; i < 5; ++i) {
            if (grade[i] == 1) {
                System.out.print(names[i] + " ");
            }
        }
        System.out.println(" (" + countGrades[0] + ")");

        System.out.print("2nd : ");
        for (int i = 0; i < 5; ++i) {
            if (grade[i] == 2) {
                System.out.print(names[i] + " ");
            }
        }
        System.out.println(" (" + countGrades[1] + ")");

        System.out.print("Fail : ");
        for (int i = 0; i < 5; ++i) {
            if (grade[i] == 3) {
                System.out.print(names[i] + " ");
            }
        }
        System.out.println(" (" + countGrades[2] + ")");
        scanner.close();
    }
}
