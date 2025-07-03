import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<TodoItem> todos = new ArrayList<>();

        todos.add(new TodoItem("Team meeting at 3PM", "Discuss project milestones", LocalDateTime.now()));
        todos.add(new TodoItem("Buy groceries", "Milk, eggs, bread", LocalDateTime.now()));
        todos.add(new TodoItem("Workout", "Leg day at the gym", LocalDateTime.now()));
        todos.add(new TodoItem("Study algorithms", "Graph traversal", LocalDateTime.now()));
        todos.add(new TodoItem("Meeting follow-up", "Send summary email", LocalDateTime.now()));

        String keyword = "meeting";
        List<TodoItem> filtered = TodoFilter.filterByKeyword(todos, keyword);

        System.out.println("[" + keyword + "] search results:");
        for (TodoItem item : filtered) {
            System.out.println(item);
        }
    }
}
