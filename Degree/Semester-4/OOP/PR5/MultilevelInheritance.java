package PR5;

class A {
    void gp() {
        System.out.println("Grandparent class method");
    }
}

class B extends A {
    void p() {
        System.out.println("Parent class method");
    }
}

class C extends B {
    void c() {
        System.out.println("Child class method");
    }

    public static void main(String[] args) {
        C obj = new C();
        obj.gp();
        obj.p();
        obj.c();
    }
}