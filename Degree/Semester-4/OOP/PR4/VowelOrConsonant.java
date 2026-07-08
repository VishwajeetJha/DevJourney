package PR4;
import java.util.Scanner;

public class VowelOrConsonant {
    public static void main(String[] args) {
        System.out.print("Enter a character: ");
        Scanner sc = new Scanner(System.in);

        char ch = Character.toLowerCase(sc.next().charAt(0));

        if (ch >= 'a' && ch <= 'z')
            System.out.println(
                (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') 
                ? "Vowel" : "Consonant"
            );
        else
            System.out.println("Not alphabet");

        sc.close();
    }
}