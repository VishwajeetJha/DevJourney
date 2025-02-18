package Java.pr6;

import java.util.Scanner;

public class Student {
    int enrollmentNo;
    String name;
    Scanner scan = new Scanner(System.in);

    void getdata() {
        System.out.println("Enter Name:");
        name = scan.nextLine();
        System.out.println("Enter Enrollment:");
        enrollmentNo = scan.nextInt();
    }

    void putdata() {
        System.out.println(name);
    }

    public static void main(String[] args) {
        Student s1 = new Student();
        Student s2 = new Student();
        Student s3 = new Student();

        System.out.println("Enter details of student s1");
        s1.getdata();
        System.out.println("Enter details of student s2");
        s2.getdata();
        System.out.println("Enter details of student s3");
        s3.getdata();

        System.out.println("The name of first student s1 is :");
        s1.putdata();
        System.out.println("The name of second student s2 is :");
        s2.putdata();
        System.out.println("The name of third student s3 is :");
        s3.putdata();

    }
}