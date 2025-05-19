import java.util.ArrayList;
import java.util.Scanner;

public class TodoCRUD {
    private ArrayList<Todo> todos;
    private Scanner scanner;

    public TodoCRUD() {
        todos = new ArrayList<>();
        scanner = new Scanner(System.in);
    }

    public void addTodo() {
        System.out.print("Title > ");
        String title = scanner.nextLine();

        System.out.print("Description > ");
        String description = scanner.nextLine();

        System.out.print("Due date > ");
        String dueDate = scanner.nextLine();

        System.out.print("Category > ");
        String category = scanner.nextLine();

        Todo todo = new Todo(title, description, dueDate, category);
        todos.add(todo);

        System.out.println("Todo added.");
    }

    public void editTodo() {
        if (todos.isEmpty()) {
            System.out.println("No todos to edit.");
            return;
        }

        listTodo();

        System.out.print("Select number to edit > ");
        int index = scanner.nextInt() - 1;
        scanner.nextLine();

        if (index < 0 || index >= todos.size()) {
            System.out.println("Invalid index.");
            return;
        }

        Todo todo = todos.get(index);

        System.out.print("New Title > ");
        String newTitle = scanner.nextLine();
        todo.setTitle(newTitle);

        System.out.print("New Description > ");
        String newDescription = scanner.nextLine();
        todo.setDescription(newDescription);

        System.out.print("New Due date > ");
        String newDueDate = scanner.nextLine();
        todo.setDueDate(newDueDate);

        System.out.print("New Category > ");
        String newCategory = scanner.nextLine();
        todo.setCategory(newCategory);

        System.out.println("Todo updated.");
    }

    public void listTodo() {
        if (todos.isEmpty()) {
            System.out.println("No todos in the list.");
            return;
        }

        for (int i = 0; i < todos.size(); ++i) {
            System.out.printf("%d. %s%n", i + 1, todos.get(i).toString());
        }
    }

    public void deleteTodo() {
        if (todos.isEmpty()) {
            System.out.println("No todos to delete.");
            return;
        }

        listTodo();

        System.out.print("Select number to delete > ");
        int index = scanner.nextInt() - 1;
        scanner.nextLine();

        if (index < 0 || index >= todos.size()) {
            System.out.println("Invalid index.");
            return;
        }

        todos.remove(index);

        System.out.println("Todo deleted.");
    }
}
