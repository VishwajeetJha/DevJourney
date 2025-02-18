interface I1{
    public void exFunc();
}

interface I2{
    public void exFunc2();
}

class mulDemo implements I1,I2{
    public void exFunc(){
        System.out.println("Interface 1");
    }
    
    public void exFunc2(){
        System.out.println("Interface 2");
    }
}

class mulDemo2 extends mulDemo{
    public void exFunc2(){
        System.out.println("Child Class");
    }
}

public class App {
    public static void main(String[] args) {
        mulDemo A = new mulDemo2();

        A.exFunc();
        A.exFunc2();
    }
}