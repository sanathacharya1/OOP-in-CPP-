
#include <iostream>
using namespace std;

class Distance {
private:
    int km, m;

public:
    // Default constructor
    Distance() {
        km = 0;
        m = 0;
    }

    // Parameterized constructor
    Distance(int k, int meters) {
        km = k;
        m = meters;
    }

    // Class to basic conversion
    operator int() {
        return km * 1000 + m;
    }

    // Basic to class conversion
    Distance(int meters) {
        km = meters / 1000;
        m = meters % 1000;
    }

    void display() {
        cout << km << " km " << m << " metres" << endl;
    }
};

int main() {
    int k, m;

    cout << "Enter kilometres: ";
    cin >> k;

    cout << "Enter metres: ";
    cin >> m;

    if (k < 0 || m < 0) {
        cout << "Invalid distance!";
        return 0;
    }

    // Create Distance object
    Distance d1(k, m);

    cout << "\nOriginal Distance: ";
    d1.display();

    // Class to basic conversion
    int totalMetres = d1;

    cout << "\nDistance in metres: " << totalMetres << endl;

    // Basic to class conversion
    int value;

    cout << "\nEnter distance in metres: ";
    cin >> value;

    if (value < 0) {
        cout << "Invalid distance!";
        return 0;
    }

    Distance d2 = value;

    cout << "\nConverted Distance: ";
    d2.display();

    return 0;
}

