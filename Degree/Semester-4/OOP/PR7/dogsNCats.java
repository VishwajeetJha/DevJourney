package PR7;

abstract class Animals {
    abstract void cats();
    abstract void dogs();
}

class Cats extends Animals {
    void cats() {
        System.out.println("Cats meow");
    }
    void dogs() {} // must override
}

class Dogs extends Animals {
    void cats() {} // must override
    void dogs() {
        System.out.println("Dogs bark");
    }
}

public class dogsNCats{
    public static void main(String[] args) {
        Cats c = new Cats();
        Dogs d = new Dogs();

        c.cats();
        d.dogs();
    }
}