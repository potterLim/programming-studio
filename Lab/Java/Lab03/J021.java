import java.util.Scanner;

public class J021 {
    public static void main(String[] args) {
        int height;
        int weight;
        double bmi;
        int people = 0;
        int countPersons;
        Scanner scanner = new Scanner(System.in);

        countPersons = scanner.nextInt();

        for (int i = 0; i < countPersons; ++i) {
            height = scanner.nextInt();
            weight = scanner.nextInt();
            bmi = weight / ((height / 100.0) * (height / 100.0));

            if (bmi >= 25) {
                ++people;
            }
        }

        System.out.println(people);
        scanner.close();
    }
}
