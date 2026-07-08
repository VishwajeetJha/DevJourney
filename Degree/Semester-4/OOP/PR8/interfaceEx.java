package PR8;

interface A {
    int x = 10;
    void showA();
}

interface A1 extends A {
    int y = 20;
    void showA1();
}

interface A2 extends A {
    int z = 30;
    void showA2();
}

interface A12 extends A1, A2 {
    int w = 40;
    void showA12();
}

public class interfaceEx implements A12{
    public void showA() {
        System.out.println("A: " + x);
    }
    public void showA1() {
        System.out.println("A1: " + y);
    }
    public void showA2() {
        System.out.println("A2: " + z);
    }
    public void showA12() {
        System.out.println("A12: " + w);
    }

    public static void main(String[] args) {
        interfaceEx obj = new interfaceEx();
        obj.showA();
        obj.showA1();
        obj.showA2();
        obj.showA12();
    }
}
