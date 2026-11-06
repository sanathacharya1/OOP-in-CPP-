#include <iostream>
#include <fstream>
using namespace std;

class Employee
{
public:
    int id;
    char name[30], department[30], designation[30];
    float basic, DA, HRA, PF, tax, gross, net;

    Employee()
    {
        id = 0;
        basic = 0;
    }

    void calculate()
    {
        DA = basic * 12 / 100;
        HRA = basic * 10 / 100;
        PF = basic * 12 / 100;

        gross = basic + DA + HRA;
        tax = gross * 5 / 100;

        net = gross - PF - tax;
    }
};

int main()
{
    Employee e;
    fstream file;
    int choice, searchID, nextID;
    bool found;

    do
    {
        cout << "\n\n1. Add Employee";
        cout << "\n2. Generate Salary Slip";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        // ADD EMPLOYEE
        if (choice == 1)
        {
            file.open("employee.dat", ios::in | ios::binary);

            if (file)
            {
                file.seekg(0, ios::end);
                nextID = file.tellg() / sizeof(Employee) + 1;
                file.close();
            }
            else
            {
                nextID = 1;
            }

            e.id = nextID;

            cout << "\nEmployee ID: " << e.id;

            cout << "\nEnter Employee Name: ";
            cin >> ws;
            cin.getline(e.name, 30);

            cout << "Enter Department: ";
            cin.getline(e.department, 30);

            cout << "Enter Designation: ";
            cin.getline(e.designation, 30);

            cout << "Enter Basic Salary: ";
            cin >> e.basic;

            if (e.basic <= 0)
            {
                cout << "Invalid salary!";
                continue;
            }

            e.calculate();

            file.open("employee.dat", ios::out |
                      ios::app | ios::binary);

            file.write((char*)&e, sizeof(e));
            file.close();

            cout << "\nEmployee added successfully!";
        }

        // GENERATE SALARY SLIP
        else if (choice == 2)
        {
            cout << "\nEnter Employee ID: ";
            cin >> searchID;

            file.open("employee.dat", ios::in | ios::binary);

            found = false;

            while (file.read((char*)&e, sizeof(e)))
            {
                if (e.id == searchID)
                {
                    found = true;

                    cout << "\n====== SALARY SLIP ======";
                    cout << "\nEmployee ID: " << e.id;
                    cout << "\nName: " << e.name;
                    cout << "\nDepartment: " << e.department;
                    cout << "\nDesignation: " << e.designation;

                    cout << "\n\nBasic Salary: Rs. " << e.basic;
                    cout << "\nDA: Rs. " << e.DA;
                    cout << "\nHRA: Rs. " << e.HRA;

                    cout << "\nGross Salary: Rs. " << e.gross;

                    cout << "\n\nPF Deduction: Rs. " << e.PF;
                    cout << "\nTax Deduction: Rs. " << e.tax;

                    cout << "\nNet Salary: Rs. " << e.net;

                    break;
                }
            }

            if (!found)
                cout << "\nEmployee not found!";

            file.close();
        }

        else if (choice == 3)
        {
            cout << "\nThank you!";
        }

        else
        {
            cout << "\nInvalid choice!";
        }

    } while (choice != 3);

    return 0;
}

