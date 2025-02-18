import java.util.ArrayList;
import java.util.LinkedList;

class pr28{
	public static void main(String[] args){	
		ArrayList<String> weekdays = new ArrayList<>();
		LinkedList<String> months = new LinkedList<>();
		
		weekdays.add("Monday");
		weekdays.add("Tuesday");
		weekdays.add("Wednesday");
		weekdays.add("Thursday");
		weekdays.add("Friday");
		weekdays.add("Saturday");
		weekdays.add("Sunday");
	
		System.out.println("Weekdays: ");
		System.out.println(weekdays);
		
		months.add("January");
		months.add("February");
		months.add("March");
		months.add("April");
		months.add("May");
		months.add("June");
		months.add("July");
		months.add("August");
		months.add("September");
		months.add("October");
		months.add("November");
		months.add("December");
		
		System.out.println("\nMonths: ");
		System.out.println(months);
	}
}
/*OUTPUT:-
 Weekdays: 
[Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday]

Months:
[January, February, March, April, May, June, July, August, September, October, November, December]

 */
