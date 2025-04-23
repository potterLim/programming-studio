public class MyString {
    public static int whichFirst(String str1, String str2) {
        String s1 = str1.toLowerCase();
        String s2 = str2.toLowerCase();

        int len = Math.min(s1.length(), s2.length());

        for (int i = 0; i < len; i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);

            if (c1 < c2) {
                return 1;
            } else if (c1 > c2) {
                return 2;
            }
        }

        if (s1.length() < s2.length()) {
            return 1;
        } else {
            return 2;
        }
    }

    public static String removeSpaces(String str) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch != ' ' && ch != '\t') {
                result.append(ch);
            }
        }

        return result.toString();
    }

    public static String findLongestWord(String str) {
        String[] words = str.split("\\s+");
        String longest = "";

        for (String word : words) {
            if (word.length() > longest.length()) {
                longest = word;
            }
        }

        return longest;
    }
}
