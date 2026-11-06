
#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    // Default constructor
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // Parameterized constructor
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Overloading + operator
    Time operator+(Time t) {
        Time result;

        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes;
        result.hours = hours + t.hours;

        // Convert extra seconds into minutes
        if (result.seconds >= 60) {
            result.minutes++;
            result.seconds = result.seconds - 60;
        }

        // Convert extra minutes into hours
        if (result.minutes >= 60) {
            result.hours++;
            result.minutes = result.minutes - 60;
        }

        return result;
    }

    // Display time
    void display() {
        cout << hours << " hours "
             << minutes << " minutes "
             << seconds << " seconds" << endl;
    }
};

int main() {
    int h1, m1, s1;
    int h2, m2, s2;

    cout << "Enter first time (hours minutes seconds): ";
    cin >> h1 >> m1 >> s1;

    cout << "Enter second time (hours minutes seconds): ";
    cin >> h2 >> m2 >> s2;

    if (h1 < 0 || m1 < 0 || s1 < 0 ||
        h2 < 0 || m2 < 0 || s2 < 0 ||
        m1 >= 60 || m2 >= 60 ||
        s1 >= 60 || s2 >= 60) {

        cout << "Invalid time!";
        return 0;
    }

    Time t1(h1, m1, s1);
    Time t2(h2, m2, s2);

    Time t3 = t1 + t2;

    cout << "\nFirst Time: ";
    t1.display();

    cout << "Second Time: ";
    t2.display();

    cout << "Total Time: ";
    t3.display();

    return 0;
}

