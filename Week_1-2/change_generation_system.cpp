
#include <iostream>
using namespace std;

int main() {
    int bill, paid, change;

    int notes[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    cout << "Enter bill amount: Rs. ";
    cin >> bill;

    cout << "Enter amount paid: Rs. ";
    cin >> paid;

    if (bill < 0 || paid < 0) {
        cout << "Invalid amount!";
        return 0;
    }

    if (paid < bill) {
        cout << "Insufficient payment!";
        return 0;
    }

    change = paid - bill;

    cout << "\nTotal change: Rs. " << change << endl;
    cout << "\nChange breakdown:\n";

    for (int i = 0; i < 9; i++) {
        int count = change / notes[i];

        if (count > 0) {
            cout << "Rs. " << notes[i]
                 << " : " << count << endl;
        }

        change = change % notes[i];
    }

    return 0;
}

