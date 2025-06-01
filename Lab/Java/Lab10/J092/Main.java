
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ParkingManager manager = new ParkingManager();
        Scanner scanner = new Scanner(System.in);
        String number;
        ParkingInfo info;
        while (true) {
            System.out.print("1) enter, 2) exit, 3) list 4) quit > ");
            int menu = scanner.nextInt();
            switch (menu) {
                case 1:
                    System.out.print("Enter number, type > ");
                    number = scanner.next();
                    String type = scanner.next();
                    manager.enter(number, type);
                    break;
                case 2: 
                    System.out.print("Enter car number to exit > ");
                    number = scanner.next();
                    info = manager.exit(number);
                    if (info == null) {
                        System.out.println("No such car parked");
                    } else {
                        Date now = new Date();
                        long mins = manager.calculateDurationMinutes(info, now);
                        int fee = manager.calculateFee(mins);
                        System.out.println(info.getCarNumber() + " " + info.getCarType() + " " + mins + "min, Parking fee " + fee + " (current time " + manager.formatDate(now) + ")");
                    }
                    break;
                case 3: 
                    System.out.println("================================");
                    System.out.printf("%-5s %-10s %-10s %s%n", "num", "number", "type", "time");
                    Map<String, ParkingInfo> map = manager.getParkingMap();
                    List<ParkingInfo> list = new ArrayList<>(map.values());
                    for (int i = 0; i < list.size(); ++i) {
                        info = list.get(i);
                        System.out.printf("%-5s %-10s %-10s %s%n", "[" + (i + 1) + "]", info.getCarNumber(), info.getCarType(), manager.formatDate(info.getEntryTime()));
                    }
                    break;
                case 4: 
                    scanner.close();
                    return;
                default: 
                    System.out.println("Invalid choice");
                    break;
            }
        }
    }
}
