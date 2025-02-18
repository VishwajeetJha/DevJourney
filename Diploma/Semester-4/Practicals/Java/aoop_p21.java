/*final class aoop_p21{
	final int x=5;
	final void add(int a, int b){
		int sum=a+b;
		System.out.println("The Value of A : "+a);
		System.out.println("The Value of B : "+b);
		System.out.println("The Sum of A and B: "+sum);
	}
	public static void main(String[] args){
		aoop_p21 a1 = new aoop_p21();
		a1.add(2,3);
		//a1.x=10; //This will Generate Error: cannot assign a value to final variable x.
		// der d = new der();
	}
// }

//class der extends aoop_p21{			This will Generate Error: cannot inherit from final aoop_p21
	// void add(int p, int q){
		// int sum = p+q;
		// System.out.println("The Value of P : "+p);
		// System.out.println("The Value of Q : "+q);
		// System.out.println("The Sum of A and B: "+sum);
	// }		 This will generate Error: add(int,int) in der cannot override add(int,int) in aoop_p21
	void show(){
		System.out.println("Hello, World!");
	}
}

/*
OUTPUT: 
class der extends aoop_p21{                     //This will Generate Error: cannot inherit from final aoop_p21
                  ^
aoop_p10.java:12: error: cannot assign a value to final variable x
                a1.x=10; //This will Generate Error: cannot assign a value to final variable x.
                  ^
aoop_p10.java:18: error: add(int,int) in der cannot override add(int,int) in aoop_p21
        void add(int p, int q){
             ^
  overridden method is final
3 errors
*/


final class def{
	void show(){
		System.out.println("Hello from Final Class");
	}
}
class aoop_p21{
public static void main(String[] args){
		def f = new def();
		f.show();
	}
}