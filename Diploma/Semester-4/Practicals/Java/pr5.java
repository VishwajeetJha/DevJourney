package Java.pr5;
import java.util.Scanner;

public class App {

    public static void main(String[] args) {
        int count = 0, a = 0, i = 1, j = 1;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter N to print first N prime number:");
        int n = scan.nextInt();
        scan.close();
        System.out.println("First" + n + "Prime number is:");
        while (a < n) {
            j = 1;
            count = 0;
            while (j <= i) {
                if (i % j == 0) {
                    count++;
                }
                j++;
            }
            if (count == 2) {
                System.out.println(i);
                a++;
            }
            i++;
        }
    }
}