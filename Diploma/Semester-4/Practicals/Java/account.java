public class account{
	public String AccHolder, AccType;
    public int AccNo, Balance;

    account(String ach, String act, int acn, int bal){
        AccHolder = ach;
        AccType = act;
        AccNo = acn;
        Balance = bal;
    }

    public void info(){
        System.out.println("\nAccount Details:-");
        System.out.println("Account Number: " + AccNo);
        System.out.println("Account Holder: " + AccHolder);
        System.out.println("Account Type: " + AccType);
        System.out.println("Balance: " + Balance);
    }

    public void debtbal(int amt){
        System.out.println("\nTrying to debit "+amt+" rs...");
        if(Balance < 1000){
            System.out.println("Balance is less than 1000! Cannot Debit!");
        }
        else{
            int newBal = Balance - amt;
            if(newBal < 1000){
                System.out.println("New Balance will be less than 1000! Cannot process further!");
            }
            else{
                Balance = newBal;
                System.out.println("New Balance: " + Balance);
            }
        }
    }
    public static void main(String[] args) {
        account a1 = new account("Suraj", "savings", 001, 2000);

        a1.info();
        a1.debtbal(200);
        a1.debtbal(900);
    }
}