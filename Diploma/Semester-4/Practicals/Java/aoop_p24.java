import java.util.Scanner;
class Excp extends Exception{
	Excp(String msg){
		super(msg);
	}
}

class Bank{
	int bal=0;
	void showbal(){
		System.out.print("Current Balance: "+this.bal + " Rs \n");
	}
	void deposite(int damt){
		System.out.println("\n"+damt + " Rs"+" Deposited Successfully");
		this.bal = this.bal+damt;
	}
	void withdraw(int wamt) throws Excp{
		if(wamt>this.bal){
			throw new Excp("\nInsufficient Balance!!!"+" You Only Have: "+this.bal + " Rs \n");
		}else{
			this.bal = this.bal-wamt;
		}
		System.out.println("\n"+wamt + " Rs"+" Withdrawed Successfully");
	}
}

class aoop_p24{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		Bank b1 = new Bank();
		while(true){
			System.out.println("\nEnter 1 to Deposite money. ");
			System.out.println("Enter 2 to Withdraw money. ");
			System.out.println("Enter 3 to Exit. ");
			System.out.print("\nEnter your Choice: ");
			int ch = scan.nextInt();
			switch (ch) {
				case 1:
					System.out.println("\nEnter Amount to Deposite");
					int dpamt = scan.nextInt();
					b1.deposite(dpamt);
					b1.showbal();
					break;
				case 2:
					System.out.println("\nEnter Amount to Withdraw");
					int wdamt = scan.nextInt();
					try{
						b1.withdraw(wdamt);
						b1.showbal();
					}
					catch(Excp e1){
						System.out.println("\nException: "+e1.getMessage());
					}
					break;
				case 3:
					scan.close();
					return;
				default:
					System.out.println("\nInvalid! Choice. ");
			}
		}
	}
}

/*
OUTPUT:

Enter 1 to Deposite money.
Enter 2 to Withdraw money.
Enter 3 to Exit.

Enter your Choice: 1   

Enter Amount to Deposite
25000

25000 Rs Deposited Successfully
Current Balance: 25000 Rs

Enter 1 to Deposite money.
Enter 2 to Withdraw money.
Enter 3 to Exit.

Enter your Choice: 2

Enter Amount to Withdraw
20000

20000 Rs Withdrawed Successfully
Current Balance: 5000 Rs

Enter 1 to Deposite money.
Enter 2 to Withdraw money.
Enter 3 to Exit.

Enter your Choice: 2

Enter Amount to Withdraw
4000

4000 Rs Withdrawed Successfully
Current Balance: 1000 Rs

Enter 1 to Deposite money.
Enter 2 to Withdraw money.
Enter 3 to Exit.

Enter your Choice: 2

Enter Amount to Withdraw
2000

Exception:
Insufficient Balance!!! You Only Have: 1000 Rs

*/