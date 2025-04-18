import java.util.Random;
import java.util.HashSet;
import java.util.Arrays;
import java.util.Scanner;

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

    public void remake() {
        Scanner scanner = new Scanner(System.in);
        HashSet<Integer> numberSet = new HashSet<>();

        System.out.printf("Enter %d unique numbers between %d and %d.%n", NUMBER_COUNT, MIN_NUMBER, MAX_NUMBER);

        while (numberSet.size() < NUMBER_COUNT) {
            System.out.printf("Number #%d: ", numberSet.size() + 1);
            if (!scanner.hasNextInt()) {
                System.out.println("Invalid input. Please enter a number.");
                scanner.next();
                continue;
            }

            int input = scanner.nextInt();
            if (input < MIN_NUMBER || input > MAX_NUMBER) {
                System.out.printf("Number must be between %d and %d. Try again.%n", MIN_NUMBER, MAX_NUMBER);
            } else if (!numberSet.add(input)) {
                System.out.println("Duplicate number. Try a different one.");
            }
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
