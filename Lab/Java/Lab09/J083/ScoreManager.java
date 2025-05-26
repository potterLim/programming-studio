import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class ScoreManager {
    private ArrayList<Score> scores;

    public ScoreManager() {
        scores = new ArrayList<>();
    }

    public boolean loadScores(String filename) throws FileNotFoundException {
        File file = new File(filename);
    
        if (!file.exists()) {
            System.out.println("File not found");
            return false;
        }
    
        Scanner fileScanner = new Scanner(file);
    
        while (fileScanner.hasNext()) {
            String name = fileScanner.next();
            if (!fileScanner.hasNextInt()) {
                break;
            }
    
            int kor = fileScanner.nextInt();
            if (!fileScanner.hasNextInt()) {
                break;
            }
    
            int eng = fileScanner.nextInt();
            if (!fileScanner.hasNextInt()) {
                break;
            }
    
            int mat = fileScanner.nextInt();
    
            Score score = new Score(name, kor, eng, mat);
            scores.add(score);
        }
    
        fileScanner.close();
        return true;
    }    

    public void printSubjectTotalAndAverage() {
        int totalKor = 0;
        int totalEng = 0;
        int totalMat = 0;

        for (int i = 0; i < scores.size(); ++i) {
            Score score = scores.get(i);
            totalKor += score.getKor();
            totalEng += score.getEng();
            totalMat += score.getMat();
        }

        double avgKor = totalKor / (double) scores.size();
        double avgEng = totalEng / (double) scores.size();
        double avgMat = totalMat / (double) scores.size();

        System.out.println("Subject Total and Average:");
        System.out.printf("Korean - Total: %d, Average: %.1f%n", totalKor, avgKor);
        System.out.printf("English - Total: %d, Average: %.1f%n", totalEng, avgEng);
        System.out.printf("Math - Total: %d, Average: %.1f%n", totalMat, avgMat);
    }

    public void printStudentTotalAndAverage() {
        System.out.println("\nStudent Total and Average:");
        for (int i = 0; i < scores.size(); ++i) {
            System.out.println(scores.get(i));
        }
    }

    public void printTopStudent() {
        if (scores.isEmpty()) {
            System.out.println("No students data.");
            return;
        }

        Score topStudent = scores.get(0);

        for (int i = 1; i < scores.size(); ++i) {
            if (scores.get(i).getAvg() > topStudent.getAvg()) {
                topStudent = scores.get(i);
            }
        }

        System.out.print("\nTop Student: ");
        System.out.println(topStudent.getName() + " - Average: " + String.format("%.1f", topStudent.getAvg()));
    }
}
