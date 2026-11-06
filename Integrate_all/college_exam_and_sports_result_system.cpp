
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student
{
public:
    int rollNo;
    char name[30], branch[20];

    Student()
    {
        rollNo = 0;
    }

    void getStudent()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> ws;
        cin.getline(name, 30);

        cout << "Enter Branch: ";
        cin.getline(branch, 20);
    }
};

class Exam : virtual public Student
{
public:
    float academicMarks;

    void getExam()
    {
        do
        {
            cout << "Enter Academic Marks (0-100): ";
            cin >> academicMarks;

            if (academicMarks < 0 || academicMarks > 100)
                cout << "Invalid marks! Try again.\n";

        } while (academicMarks < 0 || academicMarks > 100);
    }
};

class Sports : virtual public Student
{
public:
    float sportsMarks;

    void getSports()
    {
        do
        {
            cout << "Enter Sports Marks (0-100): ";
            cin >> sportsMarks;

            if (sportsMarks < 0 || sportsMarks > 100)
                cout << "Invalid marks! Try again.\n";

        } while (sportsMarks < 0 || sportsMarks > 100);
    }
};

class Result : public Exam, public Sports
{
public:
    float finalScore;
    char grade;

    Result()
    {
        finalScore = 0;
        grade = 'F';
    }

    void calculate(float academicWeight, float sportsWeight)
    {
        finalScore = (academicMarks * academicWeight / 100)
                   + (sportsMarks * sportsWeight / 100);

        if (finalScore >= 90)
            grade = 'A';
        else if (finalScore >= 80)
            grade = 'B';
        else if (finalScore >= 70)
            grade = 'C';
        else if (finalScore >= 60)
            grade = 'D';
        else
            grade = 'F';
    }

    void display()
    {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nBranch: " << branch;
        cout << "\nAcademic Marks: " << academicMarks;
        cout << "\nSports Marks: " << sportsMarks;
        cout << "\nFinal Score: " << finalScore;
        cout << "\nGrade: " << grade << endl;
    }
};

int main()
{
    Result r[50], temp;
    fstream file;

    int n, choice, searchRoll;
    float academicWeight, sportsWeight;


    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0 || n > 50)
    {
        cout << "Invalid number of students!";
        return 0;
    }

    cout << "\nEnter Academic Weightage: ";
    cin >> academicWeight;

    cout << "Enter Sports Weightage: ";
    cin >> sportsWeight;

    if (academicWeight < 0 || sportsWeight < 0 ||
        academicWeight + sportsWeight != 100)
    {
        cout << "Invalid weightages! Total must be 100.";
        return 0;
    }



    // ACCEPT STUDENT DETAILS
    for (int i = 0; i < n; i++)
    {
        cout << "\n===== STUDENT " << i + 1 << " =====";

        r[i].getStudent();
        r[i].getExam();
        r[i].getSports();

        r[i].calculate(academicWeight, sportsWeight);
    }

    // SORT STUDENTS BY FINAL SCORE
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (r[j].finalScore < r[j + 1].finalScore)
            {
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }

    // DISPLAY TOP THREE
    cout << "\n===== TOP THREE STUDENTS =====";

    for (int i = 0; i < n && i < 3; i++)
    {
        cout << "\nRank: " << i + 1;
        r[i].display();
    }

    // STORE RESULTS IN FILE
    file.open("result.dat", ios::out | ios::binary);

    for (int i = 0; i < n; i++)
    {
        file.write((char*)&r[i], sizeof(r[i]));
    }

    file.close();

    cout << "\nResults saved successfully!";

    // RETRIEVE RESULT BY ROLL NUMBER
    cout << "\n\nEnter Roll Number to search: ";
    cin >> searchRoll;

    file.open("result.dat", ios::in | ios::binary);

    bool found = false;

    while (file.read((char*)&temp, sizeof(temp)))
    {
        if (temp.rollNo == searchRoll)
        {
            cout << "\n===== RESULT FOUND =====";
            temp.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nStudent not found!";

    file.close();

    return 0;
}

