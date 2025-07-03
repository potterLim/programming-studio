import java.time.LocalDateTime;

public class TodoItem {
    private final String title;
    private final String content;
    private final LocalDateTime createdAt;

    public TodoItem(String title, String content, LocalDateTime createdAt) {
        this.title = title;
        this.content = content;
        this.createdAt = createdAt;
    }

    public String getTitle() {
        return this.title;
    }

    public String getContent() {
        return this.content;
    }

    public LocalDateTime getCreatedAt() {
        return this.createdAt;
    }

    @Override
    public String toString() {
        return "- " + this.title;
    }
}
