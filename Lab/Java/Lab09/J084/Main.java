import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("Data/input.txt");

        if (!file.exists()) {
            System.out.println("File not found");
            return;
        }

        Scanner fileScanner = new Scanner(file);
        ArrayList<String> names = new ArrayList<>();

        while (fileScanner.hasNextLine()) {
            String line = fileScanner.nextLine().trim();
            if (!line.isEmpty()) {
                names.add(line);
            }
        }

        fileScanner.close();

        if (names.isEmpty()) {
            System.out.println("No names in file.");
            return;
        }

        String longestName = names.get(0);
        String shortestName = names.get(0);

        for (int i = 1; i < names.size(); ++i) {
            String name = names.get(i);

            if (name.length() > longestName.length()) {
                longestName = name;
            }

            if (name.length() < shortestName.length()) {
                shortestName = name;
            }
        }

        System.out.println("Count : " + names.size());
        System.out.println("Longest name : " + longestName);
        System.out.println("Shortest name : " + shortestName);
    }
}
