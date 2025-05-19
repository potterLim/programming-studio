public class Todo {
    private String title;
    private String description;
    private String dueDate;
    private String category;

    public Todo(String title) {
        this.title = title;
    }

    public Todo(String title, String description, String dueDate, String category) {
        this.title = title;
        this.description = description;
        this.dueDate = dueDate;
        this.category = category;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getDueDate() {
        return dueDate;
    }

    public void setDueDate(String dueDate) {
        this.dueDate = dueDate;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    @Override
    public String toString() {
        return String.format("[Title: %s | Description: %s | Due: %s | Category: %s]", title, description, dueDate, category);
    }
}
