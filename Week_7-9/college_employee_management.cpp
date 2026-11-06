
#include <iostream>
using namespace std;

// Base class
class Employee {
protected:
    int empID;
    string name;
    float basicSalary;

public:
    Employee(int id, string n, float salary) {
        empID = id;
        name = n;
        basicSalary = salary;
    }

    void displayBasicDetails() {
        cout << "\nEmployee ID: " << empID;
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: Rs. " << basicSalary;
    }
};

// Derived class 1
class TeachingStaff : public Employee {
private:
    string subject;
    int extraClasses;

public:
    TeachingStaff(int id, string n, float salary,
                  string sub, int classes)
        : Employee(id, n, salary) {
        subject = sub;
        extraClasses = classes;
    }

    void display() {
        displayBasicDetails();

        float totalSalary = basicSalary + extraClasses * 500;

        cout << "\nStaff Type: Teaching Staff";
        cout << "\nSubject: " << subject;
        cout << "\nExtra Classes: " << extraClasses;
        cout << "\nTotal Salary: Rs. " << totalSalary << endl;
    }
};

// Derived class 2
class AdministrativeStaff : public Employee {
private:
    string department;
    int overtimeHours;

public:
    AdministrativeStaff(int id, string n, float salary,
                        string dept, int hours)
        : Employee(id, n, salary) {
        department = dept;
        overtimeHours = hours;
    }

    void display() {
        displayBasicDetails();

        float totalSalary = basicSalary + overtimeHours * 200;

        cout << "\nStaff Type: Administrative Staff";
        cout << "\nDepartment: " << department;
        cout << "\nOvertime Hours: " << overtimeHours;
        cout << "\nTotal Salary: Rs. " << totalSalary << endl;
    }
};

int main() {
    int choice, id;
    string name;
    float salary;

    cout << "1. Teaching Staff\n";
    cout << "2. Administrative Staff\n";
    cout << "Enter employee type: ";
    cin >> choice;

    cout << "Enter Employee ID: ";
    cin >> id;

    cout << "Enter Employee Name: ";
    cin >> name;

    cout << "Enter Basic Salary: ";
    cin >> salary;

    if (id <= 0 || salary < 0) {
        cout << "Invalid employee details!";
        return 0;
    }

    if (choice == 1) {
        string subject;
        int classes;

        cout << "Enter Subject: ";
        cin >> subject;

        cout << "Enter Extra Classes: ";
        cin >> classes;

        if (classes < 0) {
            cout << "Invalid number of classes!";
            return 0;
        }

        TeachingStaff t(id, name, salary, subject, classes);

        cout << "\n----- TEACHING STAFF DETAILS -----";
        t.display();
    }
    else if (choice == 2) {
        string department;
        int hours;

        cout << "Enter Department: ";
        cin >> department;

        cout << "Enter Overtime Hours: ";
        cin >> hours;

        if (hours < 0) {
            cout << "Invalid overtime hours!";
            return 0;
        }

        AdministrativeStaff a(id, name, salary,
                              department, hours);

        cout << "\n----- ADMINISTRATIVE STAFF DETAILS -----";
        a.display();
    }
    else {
        cout << "Invalid employee type!";
    }

    return 0;
}

