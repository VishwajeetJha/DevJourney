package pk22;

public class pkg{
	public void cp(int a, int b){
		int pr = 1;
		for(int i=0; i<b; i++){
			pr *= a;
		}
		System.out.println("a^b ~="+a+" ^ "+b+" = "+pr);
	}
}