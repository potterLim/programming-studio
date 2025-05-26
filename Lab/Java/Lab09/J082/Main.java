import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("Data/input.txt");

        if (!file.exists()) {
            System.out.println("File not found");
            return;
        }

        Scanner fileScanner = new Scanner(file);

        int totalPersons = 0;
        int overweightPersons = 0;

        while (fileScanner.hasNextInt()) {
            int heightCm = fileScanner.nextInt();
            if (!fileScanner.hasNextInt()) {
                break;
            }

            int weightKg = fileScanner.nextInt();

            double heightM = heightCm / 100.0;
            double bmi = weightKg / (heightM * heightM);

            ++totalPersons;

            if (bmi >= 25.0) {
                ++overweightPersons;
            }
        }

        fileScanner.close();

        if (totalPersons == 0) {
            System.out.println("No persons in data.");
            return;
        }

        double ratio = (double) overweightPersons * 100.0 / totalPersons;

        System.out.println("All " + totalPersons + " persons.");
        System.out.printf("Total overweight persons: %d (%.1f%%)%n", overweightPersons, ratio);
    }
}