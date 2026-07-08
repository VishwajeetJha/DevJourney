package PR6;

//use javac Multiple.java
//then use java MultpleCatch (10 0) OR (10 2) OR (10 a) OR (10 )

public class MultipleCatch {
    public static void main(String[] args) {
        try {
            int a = Integer.parseInt(args[0]);
            int b = Integer.parseInt(args[1]);
            int c = a / b;
            System.out.println("Result: " + c);
        } catch (ArithmeticException e) {
            System.out.println("Division by zero");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Missing arguments");
        } catch (NumberFormatException e) {
            System.out.println("Invalid number");
        }
    }
}