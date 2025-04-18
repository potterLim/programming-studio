import java.util.Random;
import java.util.HashSet;
import java.util.Arrays;

public class Lotto {
    private static final int NUMBER_COUNT = 6;
    private static final int MIN_NUMBER = 1;
    private static final int MAX_NUMBER = 45;

    private int[] numbers;

    public Lotto() {
        remakeAuto();
    }

    public void printNumbers() {
        System.out.println(Arrays.toString(numbers));
    }

    public void remakeAuto() {
        Random random = new Random();
        HashSet<Integer> numberSet = new HashSet<>();

        while (numberSet.size() < NUMBER_COUNT) {
            int randomNumber = random.nextInt(MAX_NUMBER) + MIN_NUMBER;
            numberSet.add(randomNumber);
        }

        numbers = new int[NUMBER_COUNT];
        int index = 0;

        for (int number : numberSet) {
            numbers[index] = number;
            ++index;
        }

        Arrays.sort(numbers);
    }
}
