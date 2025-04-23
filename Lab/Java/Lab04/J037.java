import java.util.Scanner;

public class J037 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String first = scanner.nextLine();
        String second = scanner.nextLine();

        int[] count1 = new int[26];
        int[] count2 = new int[26];

        for (int i = 0; i < first.length(); ++i) {
            char ch = first.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                count1[ch - 'a']++;
            }
        }

        for (int i = 0; i < second.length(); ++i) {
            char ch = second.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                count2[ch - 'a']++;
            }
        }

        boolean isAnagram = true;
        for (int i = 0; i < 26; ++i) {
            if (count1[i] != count2[i]) {
                isAnagram = false;
                break;
            }
        }

        if (isAnagram) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        scanner.close();
    }
}
