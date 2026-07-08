package PR5;

class Parent {
    void show() {
        System.out.println("Parent class method");
    }
}

class Child extends Parent {
    void Dshow() {
        System.out.println("Child class method");
    }

    public static void main(String[] args) {
        Child obj = new Child();
        obj.show();
        obj.Dshow();
    }
}
