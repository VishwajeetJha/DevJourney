package Java.pr7;
import java.util.Scanner;
class Rectangle{
	int height;
	int width;
	static Scanner Scan = new Scanner(System.in);
	Rectangle(int h, int w){
		height = h;
		width = w;
	}
	int aor(int h1, int w1){
		return h1*w1;
	}
	void show_value(){
		System.out.println("The Height of Rectangle: "+height+" cm");
		System.out.println("The Width of Rectangle: "+width+" cm");	
	}
	public static void main(String args[]){
		System.out.println("Enter Height of Rectangle: ");
		int he = Scan.nextInt();
		System.out.println("Enter Width of Rectangle: ");
		int wi = Scan.nextInt();
		Rectangle r1 = new Rectangle(he, wi);
		r1.show_value();
		System.out.println("The Area of Rectangle: "+r1.aor(he, wi)+" cm^2");	
		Scan.close();
	}
}