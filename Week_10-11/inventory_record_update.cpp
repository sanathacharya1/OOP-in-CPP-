
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Item
{
public:
    int code, quantity;
    char name[30];
    float price;
};

int main()
{
    Item i;
    fstream file;
    int choice, searchCode, nextCode;
    bool found;

    do
    {
        cout << "\n\n1. Add Item";
        cout << "\n2. Search Item";
        cout << "\n3. Update Item";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        // ADD ITEM
        if (choice == 1)
        {
            file.open("inventory.dat", ios::in | ios::binary);

            if (file)
            {
                file.seekg(0, ios::end);
                nextCode = file.tellg() / sizeof(Item) + 1;
                file.close();
            }
            else
            {
                nextCode = 1;
            }

            i.code = nextCode;

            cout << "\nItem Code: " << i.code;

            cout << "\nEnter Item Name: ";
            cin.ignore();
            cin.getline(i.name, 30);

            cout << "Enter Price: ";
            cin >> i.price;

            cout << "Enter Quantity: ";
            cin >> i.quantity;

            file.open("inventory.dat", ios::out |
                      ios::app | ios::binary);

            file.write((char*)&i, sizeof(i));
            file.close();

            cout << "\nItem added successfully!";
        }

        // SEARCH ITEM
        else if (choice == 2)
        {
            cout << "\nEnter Item Code to search: ";
            cin >> searchCode;

            file.open("inventory.dat", ios::in | ios::binary);

            found = false;

            while (file.read((char*)&i, sizeof(i)))
            {
                if (i.code == searchCode)
                {
                    cout << "\n----- ITEM DETAILS -----";
                    cout << "\nItem Code: " << i.code;
                    cout << "\nItem Name: " << i.name;
                    cout << "\nPrice: " << i.price;
                    cout << "\nQuantity: " << i.quantity;

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nItem not found!";

            file.close();
        }

        // UPDATE ITEM
        else if (choice == 3)
        {
            cout << "\nEnter Item Code to update: ";
            cin >> searchCode;

            file.open("inventory.dat", ios::in |
                      ios::out | ios::binary);

            found = false;

            while (file.read((char*)&i, sizeof(i)))
            {
                if (i.code == searchCode)
                {
                    found = true;

                    cout << "\nItem Name: " << i.name;
                    cout << "\nEnter New Price: ";
                    cin >> i.price;

                    cout << "Enter New Quantity: ";
                    cin >> i.quantity;

//                    file.seekp(-sizeof(i), ios::cur);

                    file.write((char*)&i, sizeof(i));

                    cout << "\nItem updated successfully!";

                    cout << "\n----- UPDATED RECORD -----";
                    cout << "\nItem Code: " << i.code;
                    cout << "\nItem Name: " << i.name;
                    cout << "\nNew Price: " << i.price;
                    cout << "\nNew Quantity: " << i.quantity;

                    break;
                }
            }

            if (!found)
                cout << "\nItem not found!";

            file.close();
        }

        else if (choice == 4)
        {
            cout << "\nThank you!";
        }

        else
        {
            cout << "\nInvalid choice!";
        }

    } while (choice != 4);

    return 0;
}

