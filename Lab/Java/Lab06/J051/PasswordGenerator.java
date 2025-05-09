// PasswordGenerator.java
import java.util.Random;

public class PasswordGenerator {
    private static final String CHARACTER_SET =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";

    public PasswordGenerator() {
    }

    public void generate(int length) {
        Random random = new Random();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < length; ++i) {
            int idx = random.nextInt(CHARACTER_SET.length());
            sb.append(CHARACTER_SET.charAt(idx));
        }

        System.out.println("Generated Password: " + sb.toString());
    }

    public void generateMultiple(int length, int amount) {
        for (int j = 0; j < amount; ++j) {
            generate(length);
        }
    }
}