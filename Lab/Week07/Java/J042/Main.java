public class Main {
    public static void main(String[] args) {
        Lotto lotto = new Lotto();

        System.out.print("Initial lotto numbers: ");
        lotto.printNumbers();

        System.out.println("\nPlease enter your new lotto numbers.");
        lotto.remake();
        System.out.print("Updated lotto numbers: ");
        lotto.printNumbers();
    }
}
