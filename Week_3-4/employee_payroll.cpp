#include <iostream>
using namespace std;

class Employee {
public:
    int empNo;
    string name;
    float basic, DA, tax, gross, net;

    // Constructor
    Employee() {
        empNo = 0;
        basic = 0;
        DA = 0;
        tax = 0;
        gross = 0;
        net = 0;
    }

    // Function to accept employee details
    void input() {
        cout << "\nEnter Employee Number: ";
        cin >> empNo;

        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Basic Salary: ";
        cin >> basic;
    }

    // Function to calculate salary
    void calculate() {
        DA = basic * 12 / 100;
        gross = basic + DA;
        tax = gross * 18 / 100;
        net = gross - tax;
    }

    // Function to display employee details
    void display() {
        cout << "\nEmployee Number: " << empNo;
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: Rs. " << basic;
        cout << "\nDA: Rs. " << DA;
        cout << "\nGross Salary: Rs. " << gross;
        cout << "\nIncome Tax: Rs. " << tax;
        cout << "\nNet Salary: Rs. " << net << endl;
    }
};

// Function to find employee with highest net salary
void highestSalary(Employee e[], int n) {
    int max = 0;

    for (int i = 1; i < n; i++) {
        if (e[i].net > e[max].net) {
            max = i;
        }
    }

    cout << "\n----- EMPLOYEE WITH HIGHEST NET SALARY -----";
    e[max].display();
}

int main() {
    Employee e[50];
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    if (n <= 0 || n > 50) {
        cout << "Invalid number of employees!";
        return 0;
    }

    // Accept and calculate employee details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Employee " << i + 1;

        e[i].input();
        e[i].calculate();
    }

    // Display all employees
    cout << "\n----- EMPLOYEE PAYROLL DETAILS -----";

    for (int i = 0; i < n; i++) {
        e[i].display();
    }

    // Find highest net salary
    highestSalary(e, n);

    return 0;
}
