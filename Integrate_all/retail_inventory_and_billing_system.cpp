
#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    int id, quantity;
    char name[30];
    float price;

    Product()
    {
        id = 0;
        quantity = 0;
        price = 0;
    }

    // Operator overloading to compare prices
    bool operator>(Product p)
    {
        //return price > p.price;
        if(price > p.price)
        	return true;
        return false;
    }

    void display()
    {
        cout << "\nProduct ID: " << id;
        cout << "\nProduct Name: " << name;
        cout << "\nPrice: Rs. " << price;
        cout << "\nAvailable Quantity: " << quantity << endl;
    }
};

int main()
{
    Product p, p1, p2, expensive;
    fstream file;

    int choice, searchID, nextID;
    int quantity, id1, id2;
    bool found;
    float totalValue;

    do
    {
        cout << "\n\n===== RETAIL INVENTORY SYSTEM =====";
        cout << "\n1. Add Product";
        cout << "\n2. Display All Products";
        cout << "\n3. Search Product";
        cout << "\n4. Compare Two Products";
        cout << "\n5. Generate Bill";
        cout << "\n6. Inventory Report";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        // 1. ADD PRODUCT
        if (choice == 1)
        {
            file.open("product.dat", ios::in | ios::binary);

            //nextID = 1;

            if (file)
            {
      /*         while (file.read((char*)&p, sizeof(p)))
                {
                    if (p.id >= nextID)
                        nextID = p.id + 1;
                }
                file.close();
            }
*/ 
				
				file.seekg(0,ios::end);
				nextID=file.tellg()/sizeof(Product)+1;
				file.close();
			}
			else{
				nextID=1;
			}
            p.id = nextID;

            cout << "\nProduct ID: " << p.id;

            cout << "\nEnter Product Name: ";
            cin.ignore();
            cin.getline(p.name, 30);

            cout << "Enter Price: ";
            cin >> p.price;

            cout << "Enter Quantity: ";
            cin >> p.quantity;

            if (p.price <= 0 || p.quantity < 0)
            {
                cout << "\nInvalid product details!";
                continue;
            }

            file.open("product.dat", ios::out |
                      ios::app | ios::binary);

            file.write((char*)&p, sizeof(p));
            file.close();

            cout << "\nProduct added successfully!";
        }

        // 2. DISPLAY ALL PRODUCTS
        else if (choice == 2)
        {
            file.open("product.dat", ios::in | ios::binary);

            found = false;

            while (file.read((char*)&p, sizeof(p)))
            {
                p.display();
                found = true;
            }

            if (!found)
                cout << "\nNo products found!";

            file.close();
        }

        // 3. SEARCH PRODUCT
        else if (choice == 3)
        {
            cout << "\nEnter Product ID: ";
            cin >> searchID;

            file.open("product.dat", ios::in | ios::binary);

            found = false;

            while (file.read((char*)&p, sizeof(p)))
            {
                if (p.id == searchID)
                {
                    cout << "\nProduct Found!";
                    p.display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nProduct not found!";

            file.close();
        }

        // 4. COMPARE TWO PRODUCTS
        else if (choice == 4)
        {
            cout << "\nEnter First Product ID: ";
            cin >> id1;

            cout << "Enter Second Product ID: ";
            cin >> id2;

            file.open("product.dat", ios::in | ios::binary);

            found = false;
            bool found1 = false, found2 = false;

            while (file.read((char*)&p, sizeof(p)))
            {
                if (p.id == id1)
                {
                    p1 = p;
                    found1 = true;
                }

                if (p.id == id2)
                {
                    p2 = p;
                    found2 = true;
                }
            }

            file.close();

            if (found1 && found2)
            {
                if (p1 > p2)
                    cout << "\n" << p1.name << " is more expensive.";
                else if (p2 > p1)
                    cout << "\n" << p2.name << " is more expensive.";
                else
                    cout << "\nBoth products have equal prices.";
            }
            else
            {
                cout << "\nOne or both products not found!";
            }
        }

        // 5. GENERATE BILL AND UPDATE STOCK
        else if (choice == 5)
        {
            cout << "\nEnter Product ID: ";
            cin >> searchID;

            cout << "Enter Quantity Required: ";
            cin >> quantity;

            if (quantity <= 0)
            {
                cout << "\nInvalid quantity!";
                continue;
            }

            file.open("product.dat", ios::in |
                      ios::out | ios::binary);

            found = false;

            while (true)
            {
                // Store current record position
                long pos = file.tellg();

                if (!file.read((char*)&p, sizeof(p)))
                    break;

                if (p.id == searchID)
                {
                    found = true;

                    if (quantity > p.quantity)
                    {
                        cout << "\nInsufficient stock!";
                    }
                    else
                    {
                        float bill = p.price * quantity;

                        p.quantity = p.quantity - quantity;

                        // Move writing pointer to same record
                        
                        file.seekp(pos, ios::beg);
                        
//file.seekp(-(int)sizeof(Product),ios::cur);      only if the loc of tellg is not took

                        // Update record in file
                        file.write((char*)&p, sizeof(p));

                        cout << "\n===== CUSTOMER BILL =====";
                        cout << "\nProduct Name: " << p.name;
                        cout << "\nPrice: Rs. " << p.price;
                        cout << "\nQuantity: " << quantity;
                        cout << "\nTotal Bill: Rs. " << bill;
                        cout << "\nRemaining Stock: " << p.quantity;
                    }

                    break;
                }
            }

            if (!found)
                cout << "\nProduct not found!";

            file.close();
        }

        // 6. INVENTORY REPORT
        else if (choice == 6)
        {
            file.open("product.dat", ios::in | ios::binary);

            found = false;
            totalValue = 0;

            while (file.read((char*)&p, sizeof(p)))
            {
                if (!found || p.price > expensive.price)
                    expensive = p;

                totalValue = totalValue + (p.price * p.quantity);

                found = true;
            }

            if (found)
            {
                cout << "\n===== INVENTORY REPORT =====";

                cout << "\nMost Expensive Product:";
                expensive.display();

                cout << "\nTotal Inventory Value: Rs. "
                     << totalValue;
            }
            else
            {
                cout << "\nNo products found!";
            }

            file.close();
        }

        else if (choice == 7)
        {
            cout << "\nThank you!";
        }

        else
        {
            cout << "\nInvalid choice!";
        }

    } while (choice != 7);

    return 0;
}

