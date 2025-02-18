package Java.pr12;

public class constr {
    int a,b;
    constr(){
        System.out.println("No Parameter Contructor called.");
        this.a=1;
        this.b=2;
    }
    constr(int a){
        System.out.println("Parameterised(1p) Constructor called..");
        this.a = a;
        this.b = 23;
    }
    constr(int a, int b, int c){
        System.out.println("Parameterised(3p) Constructor called..");
        this.a = a;
        this.b = b;
        c = this.a + this.b;
    }
    void putdata(){
        System.out.println("A: "+a);
        System.out.println("B: "+b);
    }


    public static void main(String[] args) {
        constr A = new constr();
        constr B = new constr(2);
        constr D = new constr(8,1,0);
        
        System.out.println("\nObject A:- ");
        A.putdata();

        System.out.println("\nObject B:- ");
        B.putdata();

        System.out.println("\nObject D:- ");
        D.putdata();
    }
}
