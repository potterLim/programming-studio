import java.util.Random;

public class MakePW {
    private static final String CHAR_SET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";

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
}
