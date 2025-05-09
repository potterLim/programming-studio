public class Main {
    public static void main(String[] args) {
        ScoreManager manager = new ScoreManager(5);
        manager.readScores();
        manager.displayScores(0, "KOR");
        manager.displayScores(1, "ENG");
        manager.displayScores(2, "MATH");
    }
}