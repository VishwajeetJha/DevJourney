package PR5;

class Animal {
    void sound() {
        System.out.println("Animal makes sound");
    }
}

class Dog extends Animal {
    void sound() {
        System.out.println("Woof!");
    }
}

public class DynamicPoly {
    public static void main(String[] args) {
        Animal obj = new Dog(); // runtime polymorphism
        obj.sound();
    }
}