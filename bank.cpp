#include <iostream>
using namespace std;

// Base Class
class BankAccount
{
protected:
    int accNo;
    string name;
    double balance;

public:
    BankAccount(int a, string n, double b)
    {
        accNo = a;
        name = n;
        balance = b;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Balance!" << endl;
    }

    virtual void calculateInterest()
    {
        cout << "No Interest" << endl;
    }

    void display()
    {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }
};

// Savings Account
class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(int a, string n, double b)
        : BankAccount(a, n, b) {}

    void calculateInterest()
    {
        cout << "Savings Interest = " << balance * 0.05 << endl;
    }
};

// Checking Account
class CheckingAccount : public BankAccount
{
public:
    CheckingAccount(int a, string n, double b)
        : BankAccount(a, n, b) {}

    void calculateInterest()
    {
        cout << "Checking Account has No Interest" << endl;
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public BankAccount
{
public:
    FixedDepositAccount(int a, string n, double b)
        : BankAccount(a, n, b) {}

    void calculateInterest()
    {
        cout << "FD Interest = " << balance * 0.08 << endl;
    }
};

int main()
{
    SavingsAccount s(101, "Ali", 10000);
    CheckingAccount c(102, "Ahmed", 15000);
    FixedDepositAccount f(103, "Usman", 20000);

    int choice;

    do
    {
        cout << "\n===== BANK SYSTEM =====";
        cout << "\n1. Show Accounts";
        cout << "\n2. Deposit in Savings";
        cout << "\n3. Withdraw from Savings";
        cout << "\n4. Calculate Interest";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            s.display();
            c.display();
            f.display();
            break;

        case 2:
            s.deposit(1000);
            cout << "1000 Deposited!";
            break;

        case 3:
            s.withdraw(500);
            cout << "500 Withdrawn!";
            break;

        case 4:
            s.calculateInterest();
            c.calculateInterest();
            f.calculateInterest();
            break;

        case 5:
            cout << "Program End!";
            break;

        default:
            cout << "Wrong Choice!";
        }

    } while(choice != 5);

    return 0;
}