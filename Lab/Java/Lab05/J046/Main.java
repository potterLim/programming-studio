import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();

        int result = MyString.whichFirst(str1, str2);

        if (result == 1) {
            System.out.println("1 " + str1);
        } else {
            System.out.println("2 " + str2);
        }

        scanner.close();
    }
}