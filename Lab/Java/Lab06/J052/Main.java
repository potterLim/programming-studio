public class Main {
    public static void main(String[] args) {
        ScoreManager scoreManager = new ScoreManager(5);
        scoreManager.readScores();
        scoreManager.displayScores();
    }
}