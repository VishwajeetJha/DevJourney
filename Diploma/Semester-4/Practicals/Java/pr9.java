package Java.pr9;

public class pr9 {
    static int cnt = 0;
    pr9(){
        cnt++;
    }
    void empty(){
    }
    static void putdata(){
        System.out.println("Total "+cnt+" objects created");
    }
    public static void main(String[] args) {
        pr9 A = new pr9();
        pr9 B = new pr9();
        pr9 C = new pr9();

        A.empty();
        B.empty();
        C.empty();

        pr9.putdata();
    }
}
