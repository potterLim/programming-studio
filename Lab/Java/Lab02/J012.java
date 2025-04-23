import java.util.Scanner;

public class J012 {
    public static void main(String[] args) {
        double areaM2;
        double areaPyung;
        double areaPyungRounded;

        Scanner scanner = new Scanner(System.in);

        areaM2 = scanner.nextDouble();
        areaPyung = areaM2 / 3.305;
        areaPyungRounded = Math.round(areaPyung * 10.0) / 10.0;

        System.out.println(areaPyungRounded);

        if (areaPyung >= 50) {
            System.out.println("huge");
        } else if (areaPyung >= 30) {
            System.out.println("large");
        } else if (areaPyung >= 15) {
            System.out.println("normal");
        } else {
            System.out.println("small");
        }

        scanner.close();
    }
}