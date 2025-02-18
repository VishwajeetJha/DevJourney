package Java.pr13;

public class str {
    public static void main(String[] args) {
        String string = "normal string test";
        int age = 22;
        
        //charAt()
        System.out.println("\nCharacter at index 4 is `"+string.charAt(4)+"` in String: "+string);
        
        //contains()
        System.out.println("\nDoes string `"+string+"` contain `normal`?: "+string.contains("normal"));

        //format()
        String formatedstring = String.format("\nThe age is: %d.", age);
        System.out.println(formatedstring);
        
        //length()
        System.out.println("\nLength of the String: "+string.length());
        
        //split()
        System.out.println("\nString with words seperated:- ");
        String sa[] = string.split(" ");
        for(String i: sa){
            System.out.println(i);
        }
        
    }
}
