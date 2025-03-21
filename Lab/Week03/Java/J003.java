import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        double areaM2;
        double areaPyung;

        Scanner scanner = new Scanner(System.in);
        areaM2 = scanner.nextDouble();

        areaPyung = areaM2 / 3.305;
        areaPyung = Math.round(areaPyung * 10.0) / 10.0;
        System.out.println(areaPyung);

        scanner.close();
    }
}