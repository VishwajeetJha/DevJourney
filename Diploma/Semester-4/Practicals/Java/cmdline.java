public class cmdline {
    public static void main(String[] args) {
        int i = 0;
        int sum = 0;
        double avg = 0.0;

        while(i<5){
            sum += Integer.parseInt(args[i]);
            i++;
        }

        avg = sum / 5;

        System.out.print("Sum of 5 integers ( ");
        i=0;
        while (i<5) {
            System.out.print(args[i]+" ");
            i++;
        }
        System.out.println("): " + sum);
        System.out.println("Average: " + avg);
    }   
}
