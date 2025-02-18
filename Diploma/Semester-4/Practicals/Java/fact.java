package Java.SPL; //uncomment this line to use it in VS
import java.util.Scanner;

public class fact {
    public static int factrec(int n){
        if (n == 0) {
            return 1;
        } else {
            return n * factrec(n-1);
        }
    }
    public static void factit(int n){
        int a = n;
        int b = 1;
        for(int i=1;i<n+1;i++){
            b = b * i;
        }
        System.out.println("The Factorial of "+a+" is: "+b);
    }
    public static void main(String[] args) {
        // n = Integer.parseInt(args[0]); // read from command line argument -- uncomment to use this, but comment the Scanner Objects'
        Scanner inp = new Scanner(System.in); // read from keyboard input
        System.out.print("Enter a number to calculate its factorial: ");
        int n = inp.nextInt();
        if (n < 0)
            System.out.println("Factorial is not defined for negative numbers");
        else if (n == 0 || n == 1)
            System.out.println("The factorial of " + n + " is: " + n);
        else {
            factit(n);  //iterative function
            System.out.println("\nThe factorial of " + n + " is: "+factrec(n)); //recursive function
        }
        inp.close();
    }
}

