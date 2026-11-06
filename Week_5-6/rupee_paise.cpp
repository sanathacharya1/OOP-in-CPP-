
#include <iostream>
using namespace std;

class Price {
private:
    int rupees, paise;

public:
    // Default constructor
    Price() {
        rupees = 0;
        paise = 0;
    }

    // Parameterized constructor
    Price(int r, int p) {
        rupees = r + p / 100;
        paise = p % 100;
    }

    // Class to basic conversion
    operator int() {
        return rupees * 100 + paise;
    }

    // Overload > operator
    bool operator>(Price p) {
        return (rupees * 100 + paise) >
               (p.rupees * 100 + p.paise);
    }

    // Overload < operator
    bool operator<(Price p) {
        return (rupees * 100 + paise) <
               (p.rupees * 100 + p.paise);
    }

    // Overload == operator
    bool operator==(Price p) {
        return (rupees == p.rupees &&
                paise == p.paise);
    }

    void display() {
        cout << "Rs. " << rupees << ".";

        if (paise < 10)
            cout << "0";

        cout << paise << endl;
    }
};

int main() {
    int r1, p1, r2, p2;

    cout << "Enter first product price (rupees paise): ";
    cin >> r1 >> p1;

    cout << "Enter second product price (rupees paise): ";
    cin >> r2 >> p2;

    if (r1 < 0 || p1 < 0 || r2 < 0 || p2 < 0) {
        cout << "Invalid price!";
        return 0;
    }

    Price price1(r1, p1);
    Price price2(r2, p2);

    cout << "\nFirst Product Price: ";
    price1.display();

    cout << "Second Product Price: ";
    price2.display();

    if (price1 > price2) {
        cout << "\nFirst product is more expensive.";
    }
    else if (price1 < price2) {
        cout << "\nSecond product is more expensive.";
    }
    else {
        cout << "\nBoth products have equal prices.";
    }

    // Convert Price object into total paise
    int totalPaise = price1;

    cout << "\n\nFirst product price in paise: "
         << totalPaise << endl;

    return 0;
}

