import java.util.Scanner;

public class J035 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String birth = scanner.nextLine();

        int yearSum = 0;
        for (int i = 0; i < 4; ++i) {
            yearSum += Integer.parseInt(birth.substring(i, i + 1));
        }

        int month = Integer.parseInt(birth.substring(4, 6));
        int day = Integer.parseInt(birth.substring(6, 8));

        int total = yearSum + month + day;
        System.out.println(total);

        scanner.close();
    }
}
