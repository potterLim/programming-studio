import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class ParkingManager {
    private Map<String,ParkingInfo> parkingMap;
    private SimpleDateFormat sdf;

    public ParkingManager() {
        parkingMap = new HashMap<>();
        sdf = new SimpleDateFormat("yyyyMMdd HHmm");
    }

    public void enter(String carNumber, String carType) {
        Date now = new Date();
        parkingMap.put(carNumber, new ParkingInfo(carNumber, carType, now));
    }

    public ParkingInfo exit(String carNumber) {
        return parkingMap.remove(carNumber);
    }

    public long calculateDurationMinutes(ParkingInfo info, Date exitTime) {
        long diff = exitTime.getTime() - info.getEntryTime().getTime();
        return diff / (1000 * 60);
    }

    public int calculateFee(long minutes) {
        if (minutes < 10) {
            return 0;
        }
        return (int)(minutes / 10) * 500;
    }

    public String formatDate(Date date) {
        return sdf.format(date);
    }

    public Map<String,ParkingInfo> getParkingMap() {
        return parkingMap;
    }
}
