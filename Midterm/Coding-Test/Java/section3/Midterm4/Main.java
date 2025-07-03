import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Student Name: ");
        String studentName = scanner.nextLine();
        System.out.print("Korean Score: ");
        int koreanScore = scanner.nextInt();
        System.out.print("English Score: ");
        int englishScore = scanner.nextInt();
        System.out.print("Math Score: ");
        int mathScore = scanner.nextInt();

        Student student = new Student(
            studentName,
            koreanScore,
            englishScore,
            mathScore
        );
        student.setGrade();
        student.printInfo();

        scanner.close();
    }
}