import java.util.Random;

public class MakePW {
    private static final String CHAR_SET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    private static final String UPPER_ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String DIGITS = "0123456789";
    private static final String DIGITS_NONZERO = "123456789";

    public MakePW() {

    }

    public void make(int length) {
        Random random = new Random();
        StringBuilder password = new StringBuilder();

        for (int i = 0; i < length; i++) {
            int index = random.nextInt(CHAR_SET.length());
            password.append(CHAR_SET.charAt(index));
        }

        System.out.println("Generated Password: " + password.toString());
    }

    public void makeCode(int length1, int length2) {
        Random random = new Random();
        StringBuilder code = new StringBuilder();

        for (int i = 0; i < length1; i++) {
            int index = random.nextInt(UPPER_ALPHABETS.length());
            code.append(UPPER_ALPHABETS.charAt(index));
        }

        code.append('-');

        if (length2 > 0) {
            int index = random.nextInt(DIGITS_NONZERO.length());
            code.append(DIGITS_NONZERO.charAt(index));

            for (int i = 1; i < length2; i++) {
                index = random.nextInt(DIGITS.length());
                code.append(DIGITS.charAt(index));
            }
        }

        System.out.println("Generated Code: " + code.toString());
    }
}
