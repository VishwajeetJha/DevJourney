package Java.pr14;
class Animal {
    public int age;
    public String name;

    public void sound(){
        System.out.println("Animal is making a sound..");
    }

}

public class Dog extends Animal{

    public Dog(int age, String name){
        this.age = age;
        this.name = name;
    }

    public void identity(){
        System.out.println("\nDog's Name is: "+name);
        System.out.println("Dog's Age is: "+age);
    }

    public void sound(){
        System.out.println("Dog is barking.. Woof Woof!");
    }

    public static void main(String[] args) {
        Animal A = new Animal();

        Dog D = new Dog(4, "Indy");

        A.sound();
        
        D.sound();

        D.identity();
        
    }
}
