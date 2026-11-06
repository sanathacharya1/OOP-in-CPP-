#include <iostream>
using namespace std;

class Shipment {
private:
    int trackingID;
    float weight, distance;

public:
    // Default constructor
    Shipment() {
        trackingID = 0;
        weight = 0;
        distance = 0;
    }

    // Parameterized constructor
    Shipment(int id, float w, float d) {
        trackingID = id;
        weight = w;
        distance = d;
    }

    // Overloaded function 1: Calculate using weight and distance
    float calculateCharge(float w, float d) {
        float weightCharge, distanceCharge;

        if (w <= 1)
            weightCharge = 50;
        else if (w <= 5)
            weightCharge = 100;
        else
            weightCharge = 200;

        if (d <= 100)
            distanceCharge = 30;
        else if (d <= 500)
            distanceCharge = 60;
        else
            distanceCharge = 100;

        return weightCharge + distanceCharge;
    }

    // Overloaded function 2: Calculate using stored details
    float calculateCharge() {
        return calculateCharge(weight, distance);
    }

    // Display shipment details
    void display() {
        cout << "\nTracking ID: " << trackingID;
        cout << "\nWeight: " << weight << " kg";
        cout << "\nDistance: " << distance << " km";
        cout << "\nShipping Charge: Rs. " << calculateCharge() << endl;
    }
};

int main() {
    int id;
    float w, d;

    // Default constructor
    Shipment s1;

    cout << "Enter Tracking ID: ";
    cin >> id;

    cout << "Enter Weight (kg): ";
    cin >> w;

    cout << "Enter Distance (km): ";
    cin >> d;

    if (id <= 0 || w <= 0 || d <= 0) {
        cout << "Invalid shipment details!";
        return 0;
    }

    // Parameterized constructor
    Shipment s2(id, w, d);

    cout << "\n----- SHIPMENT DETAILS -----";
    s2.display();

    // Using overloaded function with different inputs
    float charge = s1.calculateCharge(2, 200);

    cout << "\nCharge for another shipment (2 kg, 200 km): Rs. "
         << charge << endl;

    return 0;
}
