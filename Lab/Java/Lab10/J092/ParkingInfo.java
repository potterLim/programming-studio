import java.util.Date;

public class ParkingInfo {
    private String carNumber;
    private String carType;
    private Date entryTime;

    public ParkingInfo(String carNumber, String carType, Date entryTime) {
        this.carNumber = carNumber;
        this.carType = carType;
        this.entryTime = entryTime;
    }

    public String getCarNumber() {
        return carNumber;
    }

    public String getCarType() {
        return carType;
    }

    public Date getEntryTime() {
        return entryTime;
    }
}
