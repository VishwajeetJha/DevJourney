package PR4;
import java.util.HashMap;

public class CharacterCount {
    public static void main(String[] args) {
        String str = "hello";

        HashMap<Character, Integer> map = new HashMap<>();

        for (char ch : str.toCharArray())
            map.put(ch, map.getOrDefault(ch, 0) + 1);

        for (char ch : map.keySet())
            System.out.println(ch + " : " + map.get(ch));
    }
}