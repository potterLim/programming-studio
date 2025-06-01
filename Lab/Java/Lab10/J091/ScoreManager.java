import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ScoreManager {
    private Map<String, Score> scoreMap;

    public ScoreManager() {
        scoreMap = new HashMap<>();
    }

    public boolean loadScores(String filename) throws FileNotFoundException {
        File file = new File(filename);
        if (!file.exists()) {
            System.out.println("File not found");
            return false;
        }
        Scanner fileScanner = new Scanner(file);
        while (fileScanner.hasNext()) {
            String studentName = fileScanner.next();
            if (!fileScanner.hasNextInt()) {
                break;
            }
            int korScore = fileScanner.nextInt();
            if (!fileScanner.hasNextInt()) {
                break;
            }
            int engScore = fileScanner.nextInt();
            if (!fileScanner.hasNextInt()) {
                break;
            }
            int mathScore = fileScanner.nextInt();
            Score score = new Score(studentName, korScore, engScore, mathScore);
            scoreMap.put(studentName, score);
        }
        fileScanner.close();
        return true;
    }

    public boolean saveScores(String filename) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
            for (Score score : scoreMap.values()) {
                writer.write(score.getName() + " "
                    + score.getKor() + " "
                    + score.getEng() + " "
                    + score.getMat());
                writer.newLine();
            }
            writer.close();
            return true;
        } catch (IOException e) {
            System.out.println("Error saving file");
            return false;
        }
    }

    public void printSubjectTotalAndAverage() {
        List<Score> scoreList = new ArrayList<>(scoreMap.values());
        int count = scoreList.size();
        int totalKor = 0;
        int totalEng = 0;
        int totalMat = 0;
        for (int i = 0; i < count; ++i) {
            Score score = scoreList.get(i);
            totalKor += score.getKor();
            totalEng += score.getEng();
            totalMat += score.getMat();
        }
        double avgKor = totalKor / (double) count;
        double avgEng = totalEng / (double) count;
        double avgMat = totalMat / (double) count;
        System.out.println("Subject Total and Average:");
        System.out.printf("Korean - Total: %d, Average: %.1f%n", totalKor, avgKor);
        System.out.printf("English - Total: %d, Average: %.1f%n", totalEng, avgEng);
        System.out.printf("Math - Total: %d, Average: %.1f%n", totalMat, avgMat);
    }

    public void printStudentTotalAndAverage() {
        System.out.println("Student Total and Average:");
        List<Score> scoreList = new ArrayList<>(scoreMap.values());
        for (int i = 0; i < scoreList.size(); ++i) {
            System.out.println(scoreList.get(i));
        }
    }

    public boolean containsStudent(String studentName) {
        return scoreMap.containsKey(studentName);
    }

    public Score getStudentScore(String studentName) {
        return scoreMap.get(studentName);
    }

    public void updateStudentScore(String studentName, int korScore, int engScore, int mathScore) {
        Score newScore = new Score(studentName, korScore, engScore, mathScore);
        scoreMap.put(studentName, newScore);
    }
}