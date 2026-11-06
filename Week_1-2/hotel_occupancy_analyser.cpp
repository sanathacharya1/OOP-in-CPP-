
#include <iostream>
using namespace std;

int main() {
    int rooms[5][8];
    int floorTotal[5] = {0};

    int totalOccupancy = 0;
    int maxFloor = 0, minFloor = 0;

    // Accept occupants for each room
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter occupants for Floor " << i + 1 << ":\n";

        for (int j = 0; j < 8; j++) {
            cout << "Room " << j + 1 << ": ";
            cin >> rooms[i][j];

            if (rooms[i][j] < 0) {
                cout << "Invalid number of occupants!";
                return 0;
            }

            floorTotal[i] += rooms[i][j];
        }	

        totalOccupancy += floorTotal[i];
    }

    // Find most and least occupied floors
    maxFloor = 0;
    minFloor = 0;

    for (int i = 1; i < 5; i++) {
        if (floorTotal[i] > floorTotal[maxFloor]) {
            maxFloor = i;
        }

        if (floorTotal[i] < floorTotal[minFloor]) {
            minFloor = i;
        }
    }

    // Display floor-wise occupancy
    cout << "\n----- HOTEL OCCUPANCY REPORT -----\n";

    for (int i = 0; i < 5; i++) {
        cout << "Floor " << i + 1
             << " Occupancy: " << floorTotal[i] << endl;
    }

    cout << "\nMost occupied floor: Floor " << maxFloor + 1;
    cout << "\nLeast occupied floor: Floor " << minFloor + 1;

    cout << "\nTotal hotel occupancy: " << totalOccupancy;

    return 0;
}

