#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    float balance;

public:
    // Constructor
    BankAccount(int accNo, float amount) {
        accountNumber = accNo;
        balance = amount;
    }

    // Deposit function
    void deposit(float amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Deposit successful!" << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdrawal function
    void withdraw(float amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        }
        else if (amount <= balance) {
            balance = balance - amount;
            cout << "Withdrawal successful!" << endl;
        }
        else {
            cout << "Insufficient balance!" << endl;
        }
    }

    // Friend function declaration
    friend void transfer(BankAccount &a, BankAccount &b, float amount);

    // Display function
    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

// Friend function to transfer money
void transfer(BankAccount &a, BankAccount &b, float amount) {
    if (amount <= 0) {
        cout << "Invalid transfer amount!" << endl;
    }
    else if (amount <= a.balance) {
        a.balance = a.balance - amount;
        b.balance = b.balance + amount;

        cout << "Transfer successful!" << endl;
    }
    else {
        cout << "Insufficient balance for transfer!" << endl;
    }
}

int main() {
    int acc1, acc2;
    float bal1, bal2, amount;

    cout << "Enter first account number: ";
    cin >> acc1;

    cout << "Enter opening balance: ";
    cin >> bal1;

    cout << "\nEnter second account number: ";
    cin >> acc2;

    cout << "Enter opening balance: ";
    cin >> bal2;

    if (bal1 < 0 || bal2 < 0 || acc1 == acc2) {
        cout << "Invalid account details!";
        return 0;
    }

    // Creating two objects
    BankAccount a1(acc1, bal1);
    BankAccount a2(acc2, bal2);

    int choice;

    do {
        cout << "\n----- BANK MENU -----" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Transfer" << endl;
        cout << "4. Display Accounts" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                a1.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                a1.withdraw(amount);
                break;

            case 3:
                cout << "Enter transfer amount: ";
                cin >> amount;
                transfer(a1, a2, amount);
                break;

            case 4:
                cout << "\nFirst Account:" << endl;
                a1.display();

                cout << "\nSecond Account:" << endl;
                a2.display();
                break;

            case 5:
                cout << "Thank you!";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}
