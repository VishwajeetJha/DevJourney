class myExcp extends Exception {
    myExcp(String s) {
        super(s);
    }
}

class A23{
	void div(int a, int b)	throws myExcp{
		if(b==0){
			throw new myExcp("Division by zero not possible.");
		}
		else{
			int c=a/b;
			System.out.println("a/b"+c);
		}
	}
}

public class aoop_p23 {
    public static void main(String[] args){
		A23 obj = new A23();
		try{
		obj.div(5,0);
		}
		catch(myExcp e){
			System.out.println(e);
		}
		finally{
			System.out.println("End of Code. ");
		}
	}
}