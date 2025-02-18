class Parent {
    public void method(){
        System.out.println("Parent class method..");
    }
}

class Child extends Parent{
    public void method(){
       System.out.println("Overridden Child class method..");
    }
}

class App{
    public static void main(String[] args) {
        Parent A = new Parent();
        Parent B = new Child();

        A.method();
        B.method();
    }
}