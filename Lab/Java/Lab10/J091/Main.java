import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        ScoreManager manager = new ScoreManager();
        if (!manager.loadScores("Data/input.txt")) {
            return;
        }
        Scanner scanner = new Scanner(System.in);
        String studentName;
        while (true) {
            System.out.println("1. Print Statistics");
            System.out.println("2. Search Student");
            System.out.println("3. Update Student Scores");
            System.out.println("4. Save Scores to File");
            System.out.println("5. Exit");
            System.out.print("Select> ");
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    manager.printSubjectTotalAndAverage();
                    manager.printStudentTotalAndAverage();
                    break;
                case 2: 
                    System.out.print("Enter student name to search: ");
                    studentName = scanner.next();
                    if (manager.containsStudent(studentName)) {
                        System.out.println(manager.getStudentScore(studentName));
                    } else {
                        System.out.println("Student not found");
                    }
                    break;
                case 3: 
                    System.out.print("Enter student name to update: ");
                    studentName = scanner.next();
                    if (manager.containsStudent(studentName)) {
                        System.out.print("Enter new Korean, English, and Math scores: ");
                        int newKorScore = scanner.nextInt();
                        int newEngScore = scanner.nextInt();
                        int newMathScore = scanner.nextInt();
                        manager.updateStudentScore(studentName, newKorScore, newEngScore, newMathScore);
                        System.out.println("Scores updated in memory");
                    } else {
                        System.out.println("Student not found");
                    }
                    break;
                case 4: 
                    if (manager.saveScores("Data/output.txt")) {
                        System.out.println("All scores saved to Data/output.txt");
                    } else {
                        System.out.println("Failed to save scores");
                    }
                    break;
                case 5: 
                    System.out.println("Exiting program");
                    scanner.close();
                    return;
                default: 
                    System.out.println("Invalid choice");
                    break;
            }
        }
    }
}
