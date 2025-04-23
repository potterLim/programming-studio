import java.util.Scanner;

public class J013 {
    public static void main(String[] args) {
        int kor;
        int eng;
        int math;
        int total;
        double average;

        Scanner scanner = new Scanner(System.in);

        kor = scanner.nextInt();
        eng = scanner.nextInt();
        math = scanner.nextInt();

        total = kor + eng + math;
        average = total / 3.0;
        average = Math.round(average * 10.0) / 10.0;

        System.out.println(total + " " + average);

        System.out.print("Korean - ");
        if (kor >= 70) {
            System.out.println("Pass");
        } else {
            System.out.println("Fail");
        }

        System.out.print("English - ");
        if (eng >= 70) {
            System.out.println("Pass");
        } else {
            System.out.println("Fail");
        }

        System.out.print("Math - ");
        if (math >= 70) {
            System.out.println("Pass");
        } else {
            System.out.println("Fail");
        }

        scanner.close();
    }
}