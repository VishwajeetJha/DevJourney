package PR7;

abstract class Parent {
    abstract void message();
}

class First extends Parent {
    void message() {
        System.out.println("This is first subclass");
    }
}

class Second extends Parent {
    void message() {
        System.out.println("This is second subclass");
    }
}

public class twoClasses {
    public static void main(String[] args) {
        First f = new First();
        
        Second s = new Second();

        f.message();
        s.message();
    }
    
}
