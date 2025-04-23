import java.util.Scanner;

public class J014 {
    public static void main(String[] args) {
        int income;
        double tax;

        Scanner scanner = new Scanner(System.in);

        income = scanner.nextInt();

        if (income >= 80000000) {
            tax = income / 100.0;
            tax *= 37;
        } else if (income >= 40000000) {
            tax = income / 100.0;
            tax *= 28;
        } else if (income >= 10000000) {
            tax = income / 100.0;
            tax *= 19;
        } else {
            tax = income / 100.0;
            tax *= 9.5;
        }

        tax = Math.round(tax * 10.0) / 10.0;

        if (tax == (int) tax) {
            System.out.println((int) tax);
        } else {
            System.out.println(tax);
        }

        scanner.close();
    }
}