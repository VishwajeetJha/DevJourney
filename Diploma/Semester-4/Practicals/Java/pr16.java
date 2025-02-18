class Parent{
    public int a = 10;
    public void fn(){
        System.out.println("Parent class function called..!");
        System.out.println("Value of a: "+a);
    }
}

class Child1 extends Parent{
    public void fn(){
        System.out.println("Child class 1 function called..!");
        System.out.println("Value of a-2: "+(a-2));
    }
}

class Child2 extends Parent{
    public void fn(){
        System.out.println("Child class 2 function called..!");
        System.out.println("Value of a+3: "+(a+3));
    }
    public static void main(String[] args) {
        Child2 obj = new Child2();
        Child1 obj1 = new Child1();
        Parent pobj = new Parent();

        pobj.fn();  //calling using parent object
        obj.fn();   //calling using child 1 object
        obj1.fn();  //calling using child 2 object
    }
}
