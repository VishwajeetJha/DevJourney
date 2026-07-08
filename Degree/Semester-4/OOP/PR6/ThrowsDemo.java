package PR6;

import java.util.Scanner;

class ThrowsDemo {
    static void check(int age) throws Exception {
        if (age < 18)
            throw new Exception("Not eligible");
        else
            System.out.println("Eligible");
    }

    public static void main(String[] args) {
        System.out.print("Enter age: ");
        Scanner inp = new Scanner(System.in);
        int age = inp.nextInt();
        
        try {
            check(age);
        } catch (Exception e) {
            System.out.println("EXCEPTION! \n -> " + e.getMessage());
        }
        finally{
            inp.close();
        }
    }
}