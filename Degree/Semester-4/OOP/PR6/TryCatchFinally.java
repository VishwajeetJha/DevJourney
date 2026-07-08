package PR6;

public class TryCatchFinally {
    public static void main(String[] args) {
        try {
            int a = 10 / 0; // exception
            System.out.println("10 / 0 = " + a);
        } catch (ArithmeticException e) {
            System.out.println("Exception caught: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed");
        }
    }
}