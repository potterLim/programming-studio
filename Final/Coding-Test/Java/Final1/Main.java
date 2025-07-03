import java.util.Scanner;

public class Main {
    private static final int MAX_USERS = 100;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of users (1-100): ");
        int userCount = scanner.nextInt();
        while (userCount < 1 || userCount > MAX_USERS) {
            System.out.print("Number must be between 1 and 100. Try again: ");
            userCount = scanner.nextInt();
        }

        scanner.nextLine();

        SubscriberPicker picker = new SubscriberPicker(userCount);

        for (int i = 0; i < userCount; ++i) {
            System.out.print("Enter name of user " + (i + 1) + ": ");
            String name = scanner.nextLine();
            picker.addSubscriber(i, name);
        }

        System.out.print("Enter number of winners (1-" + userCount + "): ");
        int winnerCount = scanner.nextInt();
        while (winnerCount < 1 || winnerCount > userCount) {
            System.out.print("Number must be between 1 and " + userCount + ". Try again: ");
            winnerCount = scanner.nextInt();
        }

        String[] winners = picker.pickWinners(winnerCount);

        System.out.print("Winners: ");
        for (int i = 0; i < winners.length; ++i) {
            System.out.print(winners[i]);
            if (i < winners.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println();

        scanner.close();
    }
}
