import java.util.ArrayList;
import java.util.List;

public class TodoFilter {
    public static List<TodoItem> filterByKeyword(List<TodoItem> list, String keyword) {
        List<TodoItem> result = new ArrayList<>();

        for (TodoItem item : list) {
            if (item.getTitle().toLowerCase().contains(keyword.toLowerCase()) || item.getContent().toLowerCase().contains(keyword.toLowerCase())) {
                result.add(item);
            }
        }

        return result;
    }
}
