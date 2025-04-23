public class Main {
    public static void main(String[] args) {
        Lotto lotto = new Lotto();

        System.out.print("Initial lotto numbers: ");
        lotto.printNumbers();

        System.out.println("\nPlease enter your new lotto numbers.");
        lotto.remake();
        System.out.print("Updated lotto numbers: ");
        lotto.printNumbers();

        System.out.println("\nPlease enter this week's winning numbers.");
        Lotto winningLotto = new Lotto();
        winningLotto.remake();

        int matchCount = lotto.checkLotto(winningLotto.getNumbers());
        System.out.printf("You have %d matching number(s).%n", matchCount);
    }
}
