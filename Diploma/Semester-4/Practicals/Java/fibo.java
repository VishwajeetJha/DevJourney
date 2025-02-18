package Java.SPL;
import java.util.Scanner;

public class fibo {
    //recursive function
    public static int fibonacci(int n){
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else return fibonacci(n-1)+fibonacci(n-2);
    }

    //normal; iterative function
    public static void fib(int r) {
        int a = 0;
        int b = 1;
        int c = 0;
        System.out.print(a+" "+b+" ");
        while (r-2 > 0){
            c = a + b;
            System.out.print(c+" ");
            a=b;
            b=c;
            r--;
        }
    }
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.print("Enter a range for Fibonacci Series:");
        int r = inp.nextInt();

            //un-comment for normal; iterative function
        System.out.println("Fibonacci Series(Iterative):-");
        if(r == 0 || r == 1)
            System.out.print("0");
        else
            fib(r);

            //un-comment for recursive function
        System.out.println("\n\nFibonacci Series(Recursive):-");
        for(int i=0;i<r;i++){
            System.out.print(fibonacci(i)+" ");
        }

        inp.close();
    }
}
