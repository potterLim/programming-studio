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

        int lowerCaseCount = 0;
        int upperCaseCount = 0;
        int spaceCount = 0;

        while (fileScanner.hasNextLine()) {
            String line = fileScanner.nextLine();

            for (int i = 0; i < line.length(); ++i) {
                char c = line.charAt(i);

                if (c >= 'a' && c <= 'z') {
                    ++lowerCaseCount;
                } else if (c >= 'A' && c <= 'Z') {
                    ++upperCaseCount;
                } else if (c == ' ') {
                    ++spaceCount;
                }
            }
        }

        fileScanner.close();

        System.out.println("A~Z - " + upperCaseCount);
        System.out.println("a~z - " + lowerCaseCount);
        System.out.println("spaces - " + spaceCount);
    }
}