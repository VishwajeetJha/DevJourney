import java.util.TreeSet;

class trSet {
    public static void main(String[] args) {
        TreeSet<String> co42 = new TreeSet<>();

        co42.add("DHAIRYA");
        co42.add("ROHIT");
        co42.add("MANTHAN");
        co42.add("YASH");
        co42.add("DHAIRYA");

        System.out.println("TreeSet CO42 before changes:-\n"+co42);

        co42.remove("DHAIRYA");

        System.out.println("\nAfter:-\n"+co42);
    }
}
