
#include <iostream>
using namespace std;

// Structure to store student details
struct Student {
    string name;
    int marks[5];
    float average;
    char grade;
};

// Function to calculate grade
char calculateGrade(float avg) {
    if (avg >= 90)
        return 'A';
    else if (avg >= 75)
        return 'B';
    else if (avg >= 60)
        return 'C';
    else if (avg >= 50)
        return 'D';
    else
        return 'F';
}

int main() {
    Student s[100];

    int n;
    int subjectTotal[5] = {0};
    int passCount = 0;

    float subjectAvg[5];
    int lowestSubject = 0;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid number of students!";
        return 0;
    }

    // Accept student details and marks
    for (int i = 0; i < n; i++) {
        cout << "\nEnter student name: ";
        cin >> s[i].name;

        int total = 0;
        bool passed = true;

        for (int j = 0; j < 5; j++) {
            cout << "Enter marks in Subject " << j + 1 << ": ";
            cin >> s[i].marks[j];

            if (s[i].marks[j] < 0 || s[i].marks[j] > 100) {
                cout << "Invalid marks!";
                return 0;
            }

            total += s[i].marks[j];
            subjectTotal[j] += s[i].marks[j];

            if (s[i].marks[j] < 40) {
                passed = false;
            }
        }

        s[i].average = total / 5.0;
        s[i].grade = calculateGrade(s[i].average);

        if (passed) {
            passCount++;
        }
    }

    // Calculate subject averages
    for (int j = 0; j < 5; j++) {
        subjectAvg[j] = (float)subjectTotal[j] / n;

        if (subjectAvg[j] < subjectAvg[lowestSubject]) {
            lowestSubject = j;
        }
    }

    // Display student results
    cout << "\n----- STUDENT RESULTS -----\n";

    for (int i = 0; i < n; i++) {
        cout << "\nStudent: " << s[i].name;
        cout << "\nAverage: " << s[i].average;
        cout << "\nGrade: " << s[i].grade << endl;
    }

    // Display final analysis
    cout << "\nNumber of students passed: " << passCount;

    cout << "\n\n----- SUBJECT AVERAGES -----\n";

    for (int j = 0; j < 5; j++) {
        cout << "Subject " << j + 1
             << ": " << subjectAvg[j] << endl;
    }

    cout << "\nSubject with lowest class average: Subject "
         << lowestSubject + 1;

    cout << "\nLowest average: "
         << subjectAvg[lowestSubject] << endl;

    return 0;
}

