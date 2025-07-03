import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Final4 {
    private static final String FILE_NAME = "Data/final4_input.txt";
    private static final int TOP_COUNT = 3;

    public static void main(String[] args) {
        Map<String, Integer> wordCountMap = new HashMap<>();

        try {
            String content = Files.readString(Path.of(FILE_NAME)).toLowerCase();
            String[] words = content.split("\\W+");

            for (String word : words) {
                if (word.isEmpty()) {
                    continue;
                }

                int count = wordCountMap.getOrDefault(word, 0);
                wordCountMap.put(word, count + 1);
            }

            List<Map.Entry<String, Integer>> entryList = new ArrayList<>(wordCountMap.entrySet());

            entryList.sort(new Comparator<Map.Entry<String, Integer>>() {
                @Override
                public int compare(Map.Entry<String, Integer> a, Map.Entry<String, Integer> b) {
                    return b.getValue() - a.getValue();
                }
            });

            System.out.println("Top " + TOP_COUNT + " most frequent words:");

            for (int i = 0; i < Math.min(TOP_COUNT, entryList.size()); ++i) {
                Map.Entry<String, Integer> entry = entryList.get(i);
                System.out.printf("%d. %s - %d times%n", i + 1, entry.getKey(), entry.getValue());
            }

        } catch (IOException exception) {
            System.out.println("Failed to read the file: " + FILE_NAME);
        }
    }
}
