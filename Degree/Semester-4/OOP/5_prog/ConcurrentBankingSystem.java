import java.util.ArrayList;
import java.util.List;

public class ConcurrentBankingSystem {
    static class BankAccount {
        private final int accountId;
        private final String owner;
        private double balance;

        BankAccount(int accountId, String owner, double openingBalance) {
            this.accountId = accountId;
            this.owner = owner;
            this.balance = openingBalance;
        }

        int getAccountId() {
            return accountId;
        }

        synchronized boolean withdraw(double amount) {
            if (amount <= 0 || amount > balance) {
                return false;
            }
            balance -= amount;
            return true;
        }

        synchronized boolean deposit(double amount) {
            if (amount <= 0) {
                return false;
            }
            balance += amount;
            return true;
        }

        synchronized double getBalance() {
            return balance;
        }

        synchronized String summary() {
            return String.format("Account #%d (%s): %.2f", accountId, owner, balance);
        }
    }

    static class TransactionTask implements Runnable {
        private final BankAccount from;
        private final BankAccount to;
        private final double amount;
        private final int repeats;

        TransactionTask(BankAccount from, BankAccount to, double amount, int repeats) {
            this.from = from;
            this.to = to;
            this.amount = amount;
            this.repeats = repeats;
        }

        @Override
        public void run() {
            for (int index = 0; index < repeats; index++) {
                transfer(from, to, amount);
            }
        }

        private void transfer(BankAccount source, BankAccount target, double transferAmount) {
            BankAccount firstLock = source.getAccountId() < target.getAccountId() ? source : target;
            BankAccount secondLock = source.getAccountId() < target.getAccountId() ? target : source;

            synchronized (firstLock) {
                synchronized (secondLock) {
                    if (source.withdraw(transferAmount)) {
                        target.deposit(transferAmount);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        BankAccount accountA = new BankAccount(101, "Rahul", 50_000);
        BankAccount accountB = new BankAccount(102, "Siya", 40_000);
        BankAccount accountC = new BankAccount(103, "Kabir", 35_000);

        List<Thread> workers = new ArrayList<>();
        workers.add(new Thread(new TransactionTask(accountA, accountB, 75, 2000), "T1"));
        workers.add(new Thread(new TransactionTask(accountB, accountC, 60, 2500), "T2"));
        workers.add(new Thread(new TransactionTask(accountC, accountA, 40, 3000), "T3"));

        double beforeTotal = accountA.getBalance() + accountB.getBalance() + accountC.getBalance();

        for (Thread worker : workers) {
            worker.start();
        }
        for (Thread worker : workers) {
            worker.join();
        }

        double afterTotal = accountA.getBalance() + accountB.getBalance() + accountC.getBalance();

        System.out.println("=== Concurrent Banking System ===");
        System.out.println(accountA.summary());
        System.out.println(accountB.summary());
        System.out.println(accountC.summary());
        System.out.printf("Total before: %.2f\n", beforeTotal);
        System.out.printf("Total after : %.2f\n", afterTotal);
        System.out.println("Integrity maintained: " + (Math.abs(beforeTotal - afterTotal) < 0.0001));
    }
}
