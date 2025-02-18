import java.util.HashMap;
import java.util.Scanner;

class pr30 
{
    public static void main(String[] args) 
	{
		Scanner inp = new Scanner(System.in);
        HashMap<Integer, String> students = new HashMap<>();
    
        students.put(272, "Roshan");
        students.put(249, "Krish");
        students.put(263, "Nayan");
        
       
		while (true) 
		{
            System.out.println("Enter the Last 3 Digits of Enrollment number"); 	
			System.out.print("or Enter -1 to exit\n-->");
            int stdNo = inp.nextInt();

            if (stdNo == -1) 
			{
                System.out.println("Exiting...");
                break;
            }

            if (students.containsKey(stdNo)) 
			{
                System.out.println("Enrollment Number " + stdNo + " is " + students.get(stdNo));
            } 
			else 
			{
                System.out.println("No Student Found With Enrollment Number: "+stdNo+" in List.");
            }
        }
        inp.close();
    }
}
/*OUTPUT:-

Enter the Last 3 Digits of Enrollment number
or Enter -1 to exit
-->263
Enrollment Number 263 is Nayan
Enter the Last 3 Digits of Enrollment number
or Enter -1 to exit
-->-1
Exiting...

 */
