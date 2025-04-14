import java.util.Scanner;

public class J034 {
    public static void main(String[] args) {
        String[] usernames = {"kim", "lee", "park", "hong", "choi"};
        String[] passwords = {"1111", "1234", "3456", "3535", "7777"};

        Scanner scanner = new Scanner(System.in);
        String inputUsername = scanner.nextLine();
        String inputPassword = scanner.nextLine();

        for (int i = 0; i < usernames.length; ++i) {
            if (usernames[i].equals(inputUsername)) {
                if (inputPassword.equals(passwords[i])) {
                    System.out.println("Login OK!");
                } else {
                    System.out.println("Incorrect password!");
                }
                scanner.close();
                return;
            }
        }

        System.out.println("No user!");

        scanner.close();
    }
}
