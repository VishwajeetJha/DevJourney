package PR4;
public class WordCount {
    public static void main(String[] args) {
        String str = "Hello world this is Java";

        str = str.trim();
        if (str.isEmpty())
            System.out.println("Word count: 0");
        else
            System.out.println("Word count in : " + str.split("\\s+").length);
    }
}