#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    int playerID;
    string name;
    int matches, totalRuns, notOut;
    float average;

    // Default constructor
    Player() {
        playerID = 0;
        matches = 0;
        totalRuns = 0;
        notOut = 0;
        average = 0;
    }

    // Function to accept player details
    void getData() {
        cout << "\nEnter Player ID: ";
        cin >> playerID;

        cout << "Enter Player Name: ";
        cin >> name;

        cout << "Enter Matches Played: ";
        cin >> matches;

        cout << "Enter Total Runs: ";
        cin >> totalRuns;

        cout << "Enter Not-Out Innings: ";
        cin >> notOut;
    }

    // Function to calculate batting average
    void calculateAverage() {
        int outs = matches - notOut;

        if (outs > 0)
            average = (float)totalRuns / outs;
        else
            average = 0;
    }
};

// Overloaded function to display one player
void display(Player p) {
    cout << "\nPlayer ID: " << p.playerID;
    cout << "\nName: " << p.name;
    cout << "\nMatches: " << p.matches;
    cout << "\nTotal Runs: " << p.totalRuns;
    cout << "\nNot-Out Innings: " << p.notOut;
    cout << "\nBatting Average: " << p.average << endl;
}

// Overloaded function to display the whole team
void display(Player p[], int n) {
    cout << "\n----- TEAM STATISTICS -----\n";

    for (int i = 0; i < n; i++) {
        display(p[i]);
    }
}

int main() {
    Player p[50];
    int n, id, found = 0;

    cout << "Enter number of players: ";
    cin >> n;

    if (n <= 0 || n > 50) {
        cout << "Invalid number of players!";
        return 0;
    }

    // Accept player details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Player " << i + 1;
        p[i].getData();
        p[i].calculateAverage();
    }

    // Sort players by total runs (descending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].totalRuns < p[j + 1].totalRuns) {
                Player temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    cout << "\n----- PLAYERS SORTED BY TOTAL RUNS -----";
    display(p, n);

    // Search and display one player
    cout << "\nEnter Player ID to display individual statistics: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (p[i].playerID == id) {
            display(p[i]);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        cout << "Player not found!";
    }

    return 0;
}
