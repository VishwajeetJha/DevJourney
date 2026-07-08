package PR10;

import java.util.*;
import java.util.Date;

class Loan {
    public String toString() {
        return "Loan Object";
    }
}

class Circle {
    public String toString() {
        return "Circle Object";
    }
}

public class ArrayListDemo {
    public static void main(String[] args) {
        ArrayList<Object> list = new ArrayList<>();

        list.add(new Loan());
        list.add(new Date());
        list.add("Hello");
        list.add(new Circle());

        for (Object obj : list)
            System.out.println(obj.toString());
    }
}
