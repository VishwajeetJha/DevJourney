//Practical 20

abstract class Shape{
    public abstract double area();
}

class Triangle extends Shape{
    public double base, height;

    public Triangle(double b, double h){
        base = b;
        height = h;
    }

    public double area(){
        return 0.5*base*height;
    }
}

class Rectangle extends Shape{
    public double length, breadth;

    public Rectangle(double l, double b){
        length = l;
        breadth = b;
    }

    public double area(){
        return length*breadth;
    }
}

class Circle extends Shape{
    public double radius;

    public Circle(double r){
        radius = r;
    }

    public double area(){
        return 3.14*radius*radius;
    }
}

class pr20 {
    public static void main(String[] args) {
        Triangle T = new Triangle(2,3);
        Rectangle R = new Rectangle(4,2);
        Circle C = new Circle(3);

        System.out.println("Area of Triangle(b:2, h:3): "+T.area());
        System.out.println("Area of Rectangle(l:4, b:2): "+R.area());
        System.out.println("Area of Circle(r:3): "+C.area());
    }
}
