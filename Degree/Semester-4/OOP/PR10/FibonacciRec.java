package PR10;

public class FibonacciRec {
    static int fib(int n) {
        return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
    }

    public static void main(String[] args) {
        int val = Integer.parseInt(args[0]);

        System.out.println("Fibonacci sequence up to " + val + ":");

        for (int i = 0; i < val; i++)
            System.out.print(fib(i) + " ");
    }
}