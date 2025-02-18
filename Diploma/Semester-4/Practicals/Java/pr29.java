import java.util.HashSet;
class pr29 {
    public static void main(String[] args) {
        HashSet<String> colour = new HashSet<>();
        
        colour.add("Pink");
        colour.add("Turquoise");
        colour.add("Gold");
        colour.add("Silver");
        colour.add("Gray");
        colour.add("Purple");
        colour.add("Magenta");
        colour.add("Cyan");
        
        for (String c : colour) {
            System.out.println(c+" Colour");
        }
    }
}
/*OUTPUT:-

Gold Colour
Silver Colour
Gray Colour
Pink Colour
Cyan Colour
Purple Colour
Magenta Colour
Turquoise Colour

 */
