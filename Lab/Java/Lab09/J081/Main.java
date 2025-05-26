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


        if (!fileScanner.hasNextInt()) {
            System.out.println("No numbers in file");
            fileScanner.close();
            return;
        }

        int number = fileScanner.nextInt();
        int minNumber = number;
        int maxNumber = number;

        while (fileScanner.hasNextInt()) {
            int nextNumber = fileScanner.nextInt();

            if (nextNumber > maxNumber) {
                maxNumber = nextNumber;
            }

            if (nextNumber < minNumber) {
                minNumber = nextNumber;
            }
        }

        System.out.println("Maximum number: " + maxNumber);
        System.out.println("Minimum number: " + minNumber);

        fileScanner.close();
    }
}
