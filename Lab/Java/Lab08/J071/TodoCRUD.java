import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class TodoCRUD implements ICRUD {

    private final ArrayList<TodoItem> list;

    public TodoCRUD() {
        list = new ArrayList<TodoItem>();
    }

    @Override
    public void addItem() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Add a Todo item");
        System.out.print("Enter the title: ");
        String title = scanner.nextLine().trim();

        for (TodoItem item : list) {
            if (item.getTitle().equals(title)) {
                System.out.println("Title can't be duplicated.");
                return;
            }
        }

        System.out.print("Enter the detail: ");
        String detail = scanner.nextLine().trim();
        TodoItem newItem = new TodoItem(title, detail);
        list.add(newItem);
        System.out.println("item added.");
    }

    @Override
    public void updateItem() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Edit a Todo Item");
        System.out.print("Enter the title of the item to edit: ");
        String title = scanner.nextLine().trim();

        for (TodoItem item : list) {
            if (item.getTitle().equals(title)) {
                System.out.println(item.toString());
                System.out.print("Enter the detail: ");
                String newDetail = scanner.nextLine().trim();
                item.setDetail(newDetail);
                System.out.println("item updated.");
                return;
            }
        }

        System.out.println("Not found.");
    }

    @Override
    public void deleteItem() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Delete a Todo Item");
        System.out.print("Enter the title of the item to remove: ");
        String title = scanner.nextLine().trim();

        for (TodoItem item : list) {
            if (item.getTitle().equals(title)) {
                System.out.println(item.toString());
                list.remove(item);
                System.out.println("item deleted.");
                return;
            }
        }

        System.out.println("Not found.");
    }

    @Override
    public void printAll() {
        System.out.println("Total " + list.size() + " items");
        for (TodoItem item : list) {
            System.out.println(item.toString());
        }
    }

    public void sortByName() {
        Collections.sort(list, new Comparator<TodoItem>() {
            @Override
            public int compare(TodoItem o1, TodoItem o2) {
                return o1.getTitle().compareTo(o2.getTitle());
            }
        });
    }

    public void sortByDate() {
        Collections.sort(list, new Comparator<TodoItem>() {
            @Override
            public int compare(TodoItem o1, TodoItem o2) {
                return o1.getRegDate().compareTo(o2.getRegDate());
            }
        });
    }

    public void reverseList() {
        Collections.reverse(list);
    }
}