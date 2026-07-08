#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    int accountId;
    string owner;
    double balance;
    mutable mutex accountMutex;

public:
    BankAccount(int accountId, const string& owner, double openingBalance)
        : accountId(accountId), owner(owner), balance(openingBalance) {}

    int getAccountId() const {
        return accountId;
    }

    bool withdraw(double amount) {
        lock_guard<mutex> lock(accountMutex);
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    bool deposit(double amount) {
        lock_guard<mutex> lock(accountMutex);
        if (amount <= 0) {
            return false;
        }
        balance += amount;
        return true;
    }

    double getBalance() const {
        lock_guard<mutex> lock(accountMutex);
        return balance;
    }

    string summary() const {
        lock_guard<mutex> lock(accountMutex);
        ostringstream ss;
        ss << "Account #" << accountId << " (" << owner << "): " << fixed << setprecision(2) << balance;
        return ss.str();
    }
};

class TransactionTask {
private:
    BankAccount* from;
    BankAccount* to;
    double amount;
    int repeats;

    void transfer(BankAccount* source, BankAccount* target, double transferAmount) {
        BankAccount* firstLock = source->getAccountId() < target->getAccountId() ? source : target;
        BankAccount* secondLock = source->getAccountId() < target->getAccountId() ? target : source;

        static mutex lock1, lock2;
        lock_guard<mutex> guard1(lock1);
        lock_guard<mutex> guard2(lock2);

        if (source->withdraw(transferAmount)) {
            target->deposit(transferAmount);
        }
    }

public:
    TransactionTask(BankAccount* from, BankAccount* to, double amount, int repeats)
        : from(from), to(to), amount(amount), repeats(repeats) {}

    void operator()() {
        for (int i = 0; i < repeats; i++) {
            transfer(from, to, amount);
        }
    }
};

int main() {
    BankAccount accountA(101, "Rahul", 50000);
    BankAccount accountB(102, "Siya", 40000);
    BankAccount accountC(103, "Kabir", 35000);

    double beforeTotal = accountA.getBalance() + accountB.getBalance() + accountC.getBalance();

    vector<thread> workers;
    workers.emplace_back(TransactionTask(&accountA, &accountB, 75, 2000));
    workers.emplace_back(TransactionTask(&accountB, &accountC, 60, 2500));
    workers.emplace_back(TransactionTask(&accountC, &accountA, 40, 3000));

    for (auto& worker : workers) {
        worker.join();
    }

    double afterTotal = accountA.getBalance() + accountB.getBalance() + accountC.getBalance();

    cout << "=== Concurrent Banking System ===" << endl;
    cout << accountA.summary() << endl;
    cout << accountB.summary() << endl;
    cout << accountC.summary() << endl;
    cout << fixed << setprecision(2);
    cout << "Total before: " << beforeTotal << endl;
    cout << "Total after : " << afterTotal << endl;
    cout << "Integrity maintained: " << (abs(beforeTotal - afterTotal) < 0.0001 ? "true" : "false") << endl;

    return 0;
}
