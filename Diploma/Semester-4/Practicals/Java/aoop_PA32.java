class A{
    final int var = 22;
    public String toString(){
        return String.format("Value of var is: %d", var);
    }
}

public class aoop_PA32 {
    public static void main(String[] args) {
        A obj1 = new A();
        A obj2 = new A();

        System.out.println(obj1.toString());
        System.out.println(obj1.equals(obj2));
        System.out.println(obj1.hashCode());
    }
}
