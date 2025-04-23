import java.util.Scanner;

public class J033 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = scanner.nextInt();
        scanner.nextLine();

        String name = scanner.nextLine();
        String longest = name;
        String shortest = name;

        for (int i = 1; i < count; ++i) {
            name = scanner.nextLine();

            if (name.length() >= longest.length()) {
                if (name.length() == longest.length()) {
                    longest += ", " + name;
                } else {
                    longest = name;
                }
            }

            if (name.length() <= shortest.length()) {
                if (name.length() == shortest.length()) {
                    shortest += ", " + name;
                } else {
                    shortest = name;
                }
            }
        }

        System.out.println("Longest: " + longest);
        System.out.println("Shortest: " + shortest);

        scanner.close();
    }
}
