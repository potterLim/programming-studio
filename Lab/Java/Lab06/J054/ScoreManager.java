import java.util.Scanner;

public class ScoreManager {
    private int studentCount;
    private int[][] scores;
    private int[] studentTotals;
    private int[] subjectTotals;
    private double[] studentAverages;
    private double[] subjectAverages;

    public ScoreManager(int studentCount) {
        this.studentCount = studentCount;
    }

    public void readScores() {
        Scanner scanner = new Scanner(System.in);
        scores = new int[studentCount][3];
        studentTotals = new int[studentCount];

        for (int i = 0; i < studentCount; ++i) {
            for (int j = 0; j < 3; ++j) {
                scores[i][j] = scanner.nextInt();
                studentTotals[i] += scores[i][j];
            }
        }

        studentAverages = new double[studentCount];
        for (int i = 0; i < studentCount; ++i) {
            studentAverages[i] = studentTotals[i] / 3.0;
        }

        subjectTotals = new int[3];
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < studentCount; ++i) {
                subjectTotals[j] += scores[i][j];
            }
        }

        subjectAverages = new double[3];
        for (int j = 0; j < 3; ++j) {
            subjectAverages[j] = subjectTotals[j] / (double) studentCount;
        }
    }

    public void displayScores(int subjectIndex, String subjectName) {
        if (subjectIndex < 0 || subjectIndex >= subjectAverages.length) {
            throw new IllegalArgumentException("Invalid subject index: " + subjectIndex);
        }

        System.out.println("\n===== Subject Score (" + subjectName + ") =====");
        System.out.printf("%-8s %-6s%n", "TOTAL", "AVERAGE");

        int total = subjectTotals[subjectIndex];
        double avg = subjectAverages[subjectIndex];

        System.out.printf("%-8d %-6.1f%n", total, avg);
    }
}