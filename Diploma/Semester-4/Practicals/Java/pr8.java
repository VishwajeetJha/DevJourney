//package Java.pr8;

class pr8
 {
    int a;
    
    pr8(){
        a = 5;
        System.out.println("Default Constructor called using this keyword\nA = "+a+"\n");
    }
    
    pr8(int a){
        this();
		
        this.a=a;
        this.display();
    }
    
    void display(){ 
        System.out.println("display() function called using this keyword..\nValue of a is: "+a);
    }
    
    public void empty(){}
    
    public static void main(String[] args) {
        pr8 obj = new pr8(2);
       
        obj.empty();
    }
}