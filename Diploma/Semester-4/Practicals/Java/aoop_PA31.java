class A{
    int var;

    A(int a){
        var=a;
    }

    void disp(){
        System.out.print("Value of var= ");
    }
}

class B extends A{
    B(int val){
        super(val);
    }

    void disp(){
        super.disp();
        System.out.print(super.var);
    }
}

public class aoop_PA31 {
    public static void main(String[] args) {
        B obj = new B(3);

        obj.disp();
    }
}
