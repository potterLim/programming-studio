public class Student {
    private String name;
    private int koreanScore;
    private int englishScore;
    private int mathScore;
    private char letterGrade;

    public Student(String name, int koreanScore, int englishScore, int mathScore) {
        this.name = name;
        this.koreanScore = koreanScore;
        this.englishScore = englishScore;
        this.mathScore = mathScore;
    }

    public void setGrade() {
        double averageScore = (koreanScore + englishScore + mathScore) / 3.0;
        if (averageScore >= 90.0) {
            letterGrade = 'A';
        } else if (averageScore >= 80.0) {
            letterGrade = 'B';
        } else if (averageScore >= 70.0) {
            letterGrade = 'C';
        } else if (averageScore >= 60.0) {
            letterGrade = 'D';
        } else {
            letterGrade = 'F';
        }
    }

    public void printInfo() {
        System.out.println("Name: " + name);
        System.out.println("Korean: " + koreanScore);
        System.out.println("English: " + englishScore);
        System.out.println("Math: " + mathScore);
        System.out.println("Grade: " + letterGrade);
    }
}