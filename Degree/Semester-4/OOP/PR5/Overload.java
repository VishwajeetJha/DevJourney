package PR5;

class Overload {
    void add(int a, int b) {
        System.out.println("Sum: " + (a + b));
    }

    void add(int a, int b, int c) {
        System.out.println("Sum: " + (a + b + c));
    }

    void add(double a, double b) {
        System.out.println("Sum: " + (a + b));
    }

    public static void main(String[] args) {
        Overload obj = new Overload();
        obj.add(2, 3);
        obj.add(1, 2, 3);
        obj.add(2.5, 3.5);
    }
}