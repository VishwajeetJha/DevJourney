import java.util.Dictionary;
import java.util.Hashtable;

public class dictEx {
    public static void main(String[] args) {
        Dictionary<String, Boolean> AOOP = new Hashtable<>();
        //AOOP['String'] = ShortValue;

        AOOP.put("Monday", true);
        AOOP.put("Tuesday", true);
        AOOP.put("Wednesday", false);
        AOOP.put("Thursday", true);
        AOOP.put("Friday", true);

        System.out.println("Lecture on WED?: "+AOOP.get("Wednesday"));
    }
}
