
#include <iostream>
using namespace std;

int main() {
    double balance, amount;
    double totalDeposits = 0, totalWithdrawals = 0;
    int choice, rejected = 0;

    cout << "Enter initial wallet balance: Rs. ";
    cin >> balance;

    if (balance < 0) {
        cout << "Invalid initial balance!";
        return 0;
    }

    int n;
    cout << "Enter number of transactions: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of transactions!";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << "\nTransaction " << i << endl;
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice!" << endl;
            rejected++;
            continue;
        }

        cout << "Enter amount: Rs. ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount!" << endl;
            rejected++;
            continue;
        }

        if (choice == 1) {
            balance += amount;
            totalDeposits += amount;
            cout << "Deposit successful." << endl;
        }
        else {
            if (amount > balance) {
                cout << "Insufficient balance. Withdrawal rejected."
                     << endl;
                rejected++;
            }
            else {
                balance -= amount;
                totalWithdrawals += amount;
                cout << "Withdrawal successful." << endl;
            }
        }
    }

    cout << "\n----- WALLET SUMMARY -----" << endl;
    cout << "Final balance: Rs. " << balance << endl;
    cout << "Total deposits: Rs. " << totalDeposits << endl;
    cout << "Total withdrawals: Rs. " << totalWithdrawals << endl;
    cout << "Rejected transactions: " << rejected << endl;

    return 0;
}


