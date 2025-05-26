public class Score {
    private String name;
    private int kor;
    private int eng;
    private int mat;
    private int sum;
    private double avg;

    public Score(String name, int kor, int eng, int mat) {
        this.name = name;
        this.kor = kor;
        this.eng = eng;
        this.mat = mat;
        this.sum = kor + eng + mat;
        this.avg = sum / 3.0;
    }

    public String getName() {
        return name;
    }

    public int getKor() {
        return kor;
    }

    public int getEng() {
        return eng;
    }

    public int getMat() {
        return mat;
    }

    public int getSum() {
        return sum;
    }

    public double getAvg() {
        return avg;
    }

    @Override
    public String toString() {
        return name + " - Sum: " + sum + ", Avg: " + String.format("%.1f", avg);
    }
}
