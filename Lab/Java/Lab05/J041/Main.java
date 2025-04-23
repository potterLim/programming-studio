public class Main {
    public static void main(String[] args) {
        Lotto lotto = new Lotto();

        System.out.print("Initial lotto numbers: ");
        lotto.printNumbers();

        lotto.remakeAuto();
        System.out.print("Updated lotto numbers: ");
        lotto.printNumbers();
    }
}