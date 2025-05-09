public class Main {
    public static void main(String[] args) {
        ScoreManager manager = new ScoreManager(5);
        manager.readScores();
        for (int i = 0; i < 5; ++i) {
            manager.displayScores(i);
        }
    }
}