
#include <iostream>
using namespace std;

// Function to calculate electricity bill
float calculateBill(int units) {
    float bill;

    if (units <= 100) {
        bill = units * 2;
    }
    else if (units <= 200) {
        bill = (100 * 2) + (units - 100) * 3;
    }
    else {
        bill = (100 * 2) + (100 * 3) + (units - 200) * 5;
    }

    // Apply 10% surcharge if bill exceeds Rs. 1000
    if (bill > 1000) {
        bill = bill + (bill * 0.10);
    }

    return bill;
}

int main() {
    int n;

    cout << "Enter number of households: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid number of households!";
        return 0;
    }

    int units[100];
    float bills[100];

    float totalCollection = 0;
    int maxUnits = -1;
    int maxHouse = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter electricity units for household "
             << i + 1 << ": ";
        cin >> units[i];

        if (units[i] < 0) {
            cout << "Invalid electricity units!";
            return 0;
        }

        bills[i] = calculateBill(units[i]);

        cout << "Electricity Bill: Rs. " << bills[i] << endl;

        totalCollection += bills[i];

        if (units[i] > maxUnits) {
            maxUnits = units[i];
            maxHouse = i + 1;
        }
    }

    cout << "\n----- LOCALITY ELECTRICITY REPORT -----" << endl;

    cout << "Household with highest consumption: Household "
         << maxHouse << endl;

    cout << "Highest consumption: " << maxUnits << " units" << endl;

    cout << "Total locality collection: Rs. "
         << totalCollection << endl;

    return 0;
}

