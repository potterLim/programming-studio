public class Main {
    public static void main(String[] args) {
        MakePW pwGenerator = new MakePW();

        pwGenerator.makeCode(3, 6); // ex) ABC-391085
        pwGenerator.makeCode(5, 4); // ex) KLMNP-8357
    }
}
