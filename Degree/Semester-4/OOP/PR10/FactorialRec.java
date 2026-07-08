package PR10;

public class FactorialRec {
    static int fact(int n) {
        return (n == 0 || n == 1) ? 1 : n * fact(n - 1);
    }

    public static void main(String[] args) {
        int val = Integer.parseInt(args[0]);
        System.out.println("Factorial of "+ val + ": " + fact(val));
    }
}