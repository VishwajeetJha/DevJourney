import java.util.ArrayList;

class arrlist {
    public static void main(String[] args) {
        ArrayList<String> students = new ArrayList<>();

        students.add("KIRTAN");
        students.add("JENUL");
        students.add("NIHAL");
        students.add("SOHAM");
        students.add("HEMANK");

        System.out.println("ArrayList before modification:-");
        System.out.println(students);

        int a = students.indexOf("HEMANK");

        students.set(a, "HEMIL");

        System.out.println("\nArrayList after modification:-");
        System.out.println(students);

    }
}
