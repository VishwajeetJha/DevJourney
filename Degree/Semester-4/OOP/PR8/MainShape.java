package PR8;

interface Shape {
    void draw();
    double getArea();
}

class Circle implements Shape {
    private double r;

    void setRadius(double r) { this.r = r; }
    double getRadius() { return r; }

    public void draw() {
        System.out.println("Drawing Circle\n-> 🔴"); //CTRL + SHIFT + U and 1F534
    }

    public double getArea() {
        return Math.PI * r * r;
    }
}

class Rectangle implements Shape {
    private double l, b;

    void setDimensions(double l, double b) {
        this.l = l; this.b = b;
    }

    public void draw() {
        System.out.println("Drawing Rectangle\n-> ▬"); //CTRL + SHIFT + U and 25AC
    }

    public double getArea() {
        return l * b;
    }
}

public class MainShape {
    public static void main(String[] args) {
        Circle c = new Circle();
        c.setRadius(5);
        c.draw();
        System.out.println("Area of the Circle(r=5): " + c.getArea());

        Rectangle r = new Rectangle();
        r.setDimensions(4, 6);
        r.draw();
        System.out.println("Area of the Rectangle(l=4, b=6): " + r.getArea());
    }
}