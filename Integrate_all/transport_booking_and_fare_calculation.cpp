
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Vehicle
{
public:
    int bookingID;
    char regNo[20], model[30];
    float baseFare, distance, totalFare;

    Vehicle()
    {
        bookingID = 0;
        baseFare = 0;
        distance = 0;
        totalFare = 0;
    }

    virtual void getDetails()
    {
        cout << "\nEnter Registration Number: ";
        cin >> regNo;

        cout << "Enter Model: ";
        cin >> ws;
        cin.getline(model, 30);

        cout << "Enter Base Fare: ";
        cin >> baseFare;
    }

    virtual float calculateFare()
    {
        //return baseFare;
    }

    bool operator>(Vehicle &v)
    {
        return totalFare > v.totalFare;
    }

    virtual void display()
    {
        cout << "\nBooking ID: " << bookingID;
        cout << "\nRegistration Number: " << regNo;
        cout << "\nModel: " << model;
        cout << "\nDistance: " << distance << " km";
        cout << "\nTotal Fare: Rs. " << totalFare << endl;
    }

    virtual ~Vehicle()
    {
    }
};

class Car : public Vehicle
{
public:
    void getDetails()
    {
        cout << "\n===== ORDINARY CAR =====";
        Vehicle::getDetails();
    }

    float calculateFare()
    {
        return baseFare + (distance * 12);
    }
};

class PremiumCar : public Vehicle
{
public:
    void getDetails()
    {
        cout << "\n===== PREMIUM CAR =====";
        Vehicle::getDetails();
    }

    float calculateFare()
    {
        return (baseFare + (distance * 20)) * 1.15;
    }
};

class Van : public Vehicle
{
public:
    void getDetails()
    {
        cout << "\n===== VAN =====";
        Vehicle::getDetails();
    }

    float calculateFare()
    {
        return baseFare + (distance * 18) + 100;
    }
};

int main()
{
    Vehicle *v[50];

    int n, choice, searchID;
    int nextID = 1;

    float distance;

    fstream file;

    cout << "Enter number of bookings: ";
    cin >> n;

    if (n <= 0 || n > 50)
    {
        cout << "Invalid number of bookings!";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n===== BOOKING " << i + 1 << " =====";

        cout << "\n1. Ordinary Car";
        cout << "\n2. Premium Car";
        cout << "\n3. Van";
        cout << "\nEnter vehicle type: ";
        cin >> choice;

        if (choice == 1)
            v[i] = new Car();//v[i] = &c;   (car c)

        else if (choice == 2)
            v[i] = new PremiumCar();

        else if (choice == 3)
            v[i] = new Van();

        else
        {
            cout << "Invalid vehicle type!";
            i--;
            continue;
        }

        v[i]->bookingID = nextID++;

        v[i]->getDetails();

        if (v[i]->baseFare <= 0)
        {
            cout << "Invalid base fare!";
            delete v[i];
            i--;
            continue;
        }

        do
        {
            cout << "Enter Trip Distance: ";
            cin >> distance;

            if (distance <= 0)
                cout << "Distance must be positive!\n";

        } while (distance <= 0);

        v[i]->distance = distance;

        v[i]->totalFare = v[i]->calculateFare();

        cout << "\nCalculated Fare: Rs. "
             << v[i]->totalFare;
    }

    // COMPARE TWO VEHICLE FARES
    if (n >= 2)
    {
        int first, second;

        cout << "\n\nEnter two booking positions to compare (1 to "
             << n << "): ";

        cin >> first >> second;

        if (first >= 1 && first <= n &&
            second >= 1 && second <= n)
        {
            if (*v[first - 1] > *v[second - 1])
                cout << "\nFirst booking has higher fare.";

            else if (*v[second - 1] > *v[first - 1])
                cout << "\nSecond booking has higher fare.";

            else
                cout << "\nBoth bookings have equal fare.";
        }
        else
        {
            cout << "\nInvalid booking positions!";
        }
    }

    // DISPLAY ALL BOOKINGS
    cout << "\n\n===== ALL BOOKINGS =====";

    for (int i = 0; i < n; i++)
    {
        v[i]->display();
    }

    // SAVE BOOKINGS IN FILE
    file.open("booking.dat", ios::out | ios::binary);

    for (int i = 0; i < n; i++)
    {
        file.write((char*)v[i], sizeof(Vehicle));
    }

    file.close();

    cout << "\nBookings saved successfully!";

    // SEARCH BOOKING BY ID
    cout << "\n\nEnter Booking ID to search: ";
    cin >> searchID;

    file.open("booking.dat", ios::in | ios::binary);

    Vehicle temp;
    bool found = false;

    while (file.read((char*)&temp, sizeof(temp)))
    {
        if (temp.bookingID == searchID)
        {
            cout << "\n===== BOOKING FOUND =====";
            temp.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nBooking not found!";

    file.close();

    // FREE DYNAMIC MEMORY
    for (int i = 0; i < n; i++)
    {
        delete v[i];
    }

    return 0;
}

