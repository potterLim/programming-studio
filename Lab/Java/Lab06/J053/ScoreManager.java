import java.util.Scanner;

public class ScoreManager {
    private int studentCount;
    private int[][] scores;
    private int[] totalScores;
    private double[] averageScores;

    public ScoreManager(int studentCount) {
        this.studentCount = studentCount;
    }

    public void readScores() {
        Scanner scanner = new Scanner(System.in);
        this.scores = new int[studentCount][3];
        this.totalScores = new int[studentCount];

        for (int i = 0; i < studentCount; ++i) {
            for (int j = 0; j < 3; ++j) {
                this.scores[i][j] = scanner.nextInt();
                this.totalScores[i] += this.scores[i][j];
            }
        }

        this.averageScores = new double[studentCount];
        for (int i = 0; i < studentCount; ++i) {
            this.averageScores[i] = this.totalScores[i] / 3.0;
        }
    }

    public void displayScores(int index) {
        assert(index >= 0 && index < studentCount);
        System.out.println("\n===== Student Score (" + index + ") =====");
        System.out.printf("%-4s %-5s %-5s %-5s %-6s %-8s %-6s\n", "No.", "KOR", "ENG", "MATH", "TOTAL", "AVERAGE", "GRADE");
        int scoreKor = this.scores[index][0];
        int scoreEng = this.scores[index][1];
        int scoreMath = this.scores[index][2];
        int total = this.totalScores[index];
        double avg = this.averageScores[index];
        double roundedAvg = Math.floor(avg * 10) / 10.0;

        char grade;
        if (avg >= 90.0) {
            grade = 'A';
        } else if (avg >= 80.0) {
            grade = 'B';
        } else if (avg >= 70.0) {
            grade = 'C';
        } else if (avg >= 60.0) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        System.out.printf("%-4d %-5d %-5d %-5d %-6d %-8.1f %-6c%n",
            index, scoreKor, scoreEng, scoreMath, total, roundedAvg, grade);
    }
}