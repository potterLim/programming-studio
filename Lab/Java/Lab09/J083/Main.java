import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        ScoreManager manager = new ScoreManager();
        
        if (!manager.loadScores("Data/input.txt")) {
            return;
        }

        manager.printSubjectTotalAndAverage();
        manager.printStudentTotalAndAverage();
        manager.printTopStudent();
    }
}
