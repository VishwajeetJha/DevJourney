package Java.pr15;
// import Java.pr14.*;

// public class Puppy extends Dog{
//     boolean cute = true;

//     Puppy(int a, String nm){
//         super(a, nm);
//     }
    
//     public void aadhaar(){
//         super.identity();
//         System.out.println("Puppy is cute: "+cute);
//     }

//     public void sound(){
//         System.out.println("Puppy is balking...! Woof-Woof!");
//     }



//     public static void main(String[] args) {
//         Puppy A = new Puppy(1, "Ice Cream");

//         A.aadhaar();
//         A.sound();
//     }
// }




class parent{
	int a=10, b=5;
	void show(){
		System.out.println("Value of A: "+a);
		System.out.println("Value of B: "+b);
	}

	void add(){
		int sum = a+b;
		System.out.println("Sum of A + B: "+sum);
	}
}

class child1 extends parent{
	void sub(){
		int diff = a-b;
		System.out.println("Difference of A - B: "+diff);
	}
}

class child2 extends child1{
	void mul(){
		int pro = a*b;
		System.out.println("Product of A * B: "+pro);
	}	
	void div(){
		int div = a/b;
		int mod = a%b;
		System.out.println("Division of A / B: "+div);
		System.out.println("Remainder of A % B: "+mod);
	}
}


class Main {
	public static void main(String[] args){
		child2 c = new child2();
		c.show();
		c.add();
		c.sub();
		c.mul();
		c.div();
	}
}