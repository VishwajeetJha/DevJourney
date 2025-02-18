package Java.pr11;

public class Shape {
    double area;
    void calcArea(double a){
        area = 3.14*a*a;
        System.out.println("Area of the Circle: "+area);
    }
    void calcArea(double a, double b){
        area = a*b;
        System.out.println("Area of the Rectangle: "+area);
    }

    public static void main(String[] args) {
        Shape Circle = new Shape(); 
        Shape Rectangle = new Shape();

        Circle.calcArea(3); 
        Rectangle.calcArea(2, 4);
    }
}
