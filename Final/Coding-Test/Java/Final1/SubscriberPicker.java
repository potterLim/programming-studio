import java.util.Random;

public class SubscriberPicker {
    private final String[] subscribers;
    private final int count;

    public SubscriberPicker(int userCount) {
        this.subscribers = new String[userCount];
        this.count = userCount;
    }

    public void addSubscriber(int index, String name) {
        assert (index >= 0 && index < this.count) : "Index out of bounds";
        this.subscribers[index] = name;
    }

    public String[] pickWinners(int winnerCount) {
        assert (winnerCount <= this.count) : "Winner count exceeds subscriber count";

        String[] copy = new String[this.count];
        for (int i = 0; i < this.count; ++i) {
            copy[i] = this.subscribers[i];
        }

        shuffle(copy);

        String[] result = new String[winnerCount];
        for (int i = 0; i < winnerCount; ++i) {
            result[i] = copy[i];
        }

        return result;
    }

    private void shuffle(String[] array) {
        Random random = new Random();

        for (int i = array.length - 1; i > 0; --i) {
            int j = random.nextInt(i + 1);
            String temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}
