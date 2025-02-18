//practical 2: maximum among three numbers

public class App {
    public static void main(String[] args) {
        int a = 4;
        int b = 7;
        int c = 6; //earlier it was 9

        System.out.println("Maximum is "+ ((a > b) ? (a > c ? a : c) : (b > c ? b : c)));

        // if (a>b && a>c){
        //     System.out.println("A is greatest");
        // }
        // else if(b>a && b>c){
        //     System.out.println("B is greatest");
        // }
        // else{
        //     System.out.println("C is greatest");
        // } 
    }
}

