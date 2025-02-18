package Java.SPL;

public class nest_class {
    static class inner{
        public int a = 2;

        public void display(){
            System.out.println("Value of a is: "+a);
        }
    }

    public static void main(String[] args) {
        inner A = new inner();
        A.display(); 
    }
}
