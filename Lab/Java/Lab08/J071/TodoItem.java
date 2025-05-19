import java.util.Date;
import java.text.SimpleDateFormat;

public class TodoItem {

    private String title;
    private String detail;
    private Date regDate;

    public TodoItem(String title, String detail) {
        this.title = title;
        this.detail = detail;
        this.regDate = new Date();
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDetail() {
        return detail;
    }

    public void setDetail(String detail) {
        this.detail = detail;
    }

    public Date getRegDate() {
        return regDate;
    }

    public void setRegDate(Date regDate) {
        this.regDate = regDate;
    }

    @Override
    public String toString() {
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy/MM/dd");
        return "[" + title + "] " + detail + " - " + formatter.format(regDate);
    }
}