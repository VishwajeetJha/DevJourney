//practical 3: reverse a number using while loop
public class App {
    public static void main(String[] args){
        //reversing a number...
		int a = 1234, temp = a, rev=0, rem = 0;

		while (temp > 0) {
            rem = temp % 10;
            rev = (rev*10) + rem;
            temp = temp / 10;
        }

        System.out.println("Reverse of "+a+" is "+rev);
    }
}
