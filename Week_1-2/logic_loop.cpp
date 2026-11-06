
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;

    cout << "Enter number of vehicles: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of vehicles!";
        return 0;
    }

    double hours[100];
    int fee[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter parking hours for vehicle " << i + 1 << ": ";
        cin >> hours[i];

        if (hours[i] <= 0) {
            cout << "Invalid parking hours!";
            return 0;
        }

        int h = ceil(hours[i]);

        if (h == 1) {
            fee[i] = 30;
        }
        else if (h <= 5) {
            fee[i] = 30 + (h - 1) * 20;
        }
        else {
            fee[i] = 30 + 4 * 20 + (h - 5) * 10;
        }

        cout << "Vehicle " << i + 1
             << " fee: Rs. " << fee[i] << endl;
    }

    int maxFee = fee[0];
    int maxVehicle = 1;

    for (int i = 1; i < n; i++) {
        if (fee[i] > maxFee) {
            maxFee = fee[i];
            maxVehicle = i + 1;
        }
    }

    cout << "\nVehicle with highest fee: Vehicle "
         << maxVehicle << endl;
    cout << "Highest fee: Rs. " << maxFee << endl;
    cout<<"vehicles with same fee: \n";
	for(int i=0;i<n;i++){
		if(fee[i]==maxFee){
			cout<<"vehicle: "<<i+1<<" share high fee: "<<maxFee<<"\n";
		}
	}
    return 0;
}

