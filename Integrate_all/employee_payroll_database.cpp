
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Employee
{
public:
    int empID;
    int type;

    char name[30];

    float basic, da, hra, allowance;
    float gross, tax, net;

    Employee()
    {
        empID = 0;
        type = 0;

        basic = da = hra = allowance = 0;
        gross = tax = net = 0;

        strcpy(name, "");
    }

    virtual void getDetails()
    {
        cout << "\nEnter Employee Name: ";
        cin >> ws;
        cin.getline(name, 30);

        cout << "Enter Basic Salary: ";
        cin >> basic;
    }

    virtual void calculateSalary()
    {
        da = basic * 0.12;
        hra = basic * 0.20;

        gross = basic + da + hra + allowance;

        tax = gross * 0.10;

        net = gross - tax;
    }

    bool operator>(Employee &e)
    {
        return net > e.net;
    }

    virtual void display()
    {
        cout << "\n------ SALARY SLIP ------";
        cout << "\nEmployee ID: " << empID;
        cout << "\nName: " << name;
        cout << "\nBasic Salary: " << basic;
        cout << "\nDA: " << da;
        cout << "\nHRA: " << hra;
        cout << "\nAllowance: " << allowance;
        cout << "\nGross Salary: " << gross;
        cout << "\nIncome Tax: " << tax;
        cout << "\nNet Salary: " << net << endl;
    }

    virtual ~Employee() {}
};

class TeachingEmployee : public Employee
{
public:
    void getDetails()
    {
        cout << "\n--- TEACHING EMPLOYEE ---";

        Employee::getDetails();

        type = 1;
        allowance = 3000;
    }
};

class AdministrativeEmployee : public Employee
{
public:
    void getDetails()
    {
        cout << "\n--- ADMINISTRATIVE EMPLOYEE ---";

        Employee::getDetails();

        type = 2;
        allowance = basic * 0.10;
    }
};

int main()
{
    Employee *e[50];

    int n, choice, searchID;
    int nextID = 1;

    fstream file;

    cout << "Enter number of employees: ";
    cin >> n;

    if (n <= 0 || n > 50)
    {
        cout << "Invalid number of employees!";
        return 0;
    }

    // Enter employee details
    for (int i = 0; i < n; i++)
    {
        cout << "\n1. Teaching Employee";
        cout << "\n2. Administrative Employee";
        cout << "\nEnter employee type: ";
        cin >> choice;

        if (choice == 1)
            e[i] = new TeachingEmployee();

        else if (choice == 2)
            e[i] = new AdministrativeEmployee();

        else
        {
            cout << "Invalid choice!";
            i--;
            continue;
        }

        e[i]->empID = nextID++;

        e[i]->getDetails();

        if (e[i]->basic <= 0)
        {
            cout << "Invalid salary!";
            delete e[i];
            i--;
            continue;
        }

        e[i]->calculateSalary();

        e[i]->display();
    }

    // Store employee records
    file.open("employee.dat", ios::binary | ios::out);

    if (!file)
    {
        cout << "File opening error!";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        file.write((char*)e[i], sizeof(Employee));
    }

    file.close();

    // Search employee by ID
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    Employee temp;

    file.open("employee.dat", ios::binary | ios::in);

    bool found = false;

    while (file.read((char*)&temp, sizeof(Employee)))
    {
        if (temp.empID == searchID)
        {
            found = true;
            temp.display();
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nEmployee not found!";

    // Update employee salary
    cout << "\nEnter Employee ID to update: ";
    cin >> searchID;

    file.open("employee.dat", ios::binary | ios::in | ios::out);

    found = false;

    while (file.read((char*)&temp, sizeof(Employee)))
    {
        if (temp.empID == searchID)
        {
            found = true;

            cout << "Enter new Basic Salary: ";
            cin >> temp.basic;

            if (temp.basic <= 0)
            {
                cout << "Invalid salary!";
                break;
            }

            temp.da = temp.basic * 0.12;
            temp.hra = temp.basic * 0.20;

            if (temp.type == 2)
                temp.allowance = temp.basic * 0.10;

            temp.gross = temp.basic + temp.da +
                         temp.hra + temp.allowance;

            temp.tax = temp.gross * 0.10;

            temp.net = temp.gross - temp.tax;

            file.seekp(-(int)sizeof(Employee), ios::cur);

            file.write((char*)&temp, sizeof(Employee));

            cout << "\nSalary updated!";
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nEmployee not found!";

    // Find highest net salary
    Employee highest;
    bool first = true;

    file.open("employee.dat", ios::binary | ios::in);

    while (file.read((char*)&temp, sizeof(Employee)))
    {
        if (first || temp.net > highest.net)
        {
            highest = temp;
            first = false;
        }
    }

    file.close();

    if (!first)
    {
        cout << "\n\n--- HIGHEST PAID EMPLOYEE ---";
        highest.display();
    }

    // Compare two employees
    if (n >= 2)
    {
        int a, b;

        cout << "\nEnter two employee positions to compare: ";
        cin >> a >> b;

        if (a >= 1 && a <= n && b >= 1 && b <= n)
        {
            if (*e[a - 1] > *e[b - 1])
                cout << "\nFirst employee has higher net salary.";

            else if (*e[b - 1] > *e[a - 1])
                cout << "\nSecond employee has higher net salary.";

            else
                cout << "\nBoth have equal net salary.";
        }
        else
            cout << "\nInvalid positions!";
    }

    for (int i = 0; i < n; i++)
        delete e[i];

    return 0;
}

