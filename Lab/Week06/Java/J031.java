import java.util.Scanner;

public class J031 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String userId = scanner.nextLine();
        String password = scanner.nextLine();
        String name = scanner.nextLine();

        if (password.length() < 3) {
            System.out.println("Error! password is too short");
            scanner.close();
            return;
        }

        System.out.println("User Id: " + userId);
        System.out.print("Password: ");
        for (int i = 0; i < password.length(); ++i) {
            if (i < 2) {
                System.out.print(password.charAt(i));
            } else {
                System.out.print("*");
            }
        }

        System.out.println();
        System.out.println("User Name: " + name);
        
        scanner.close();
    }
}
