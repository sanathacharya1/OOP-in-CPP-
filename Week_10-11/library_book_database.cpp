
#include <iostream>
#include <fstream>
using namespace std;

class Book
{
public:
    int code, pages;
    char title[50], author[50];
};

int main()
{
    Book b;
    fstream file;
    int choice, searchCode;
    char searchName[50];
    int nextCode;
    bool found;

    do
    {
        cout << "\n1. Add Book";
        cout << "\n2. Search Book";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            file.open("library.dat", ios::in | ios::binary);

            if (file)
            {
                file.seekg(0, ios::end);
                nextCode = file.tellg() / sizeof(Book) + 1;
                file.close();
            }
            else
            {
                nextCode = 1;
            }

            b.code = nextCode;

            cout << "\nAccession Number: " << b.code;

            cout << "\nEnter Book Title: ";
            cin >> ws;
            cin.getline(b.title, 50);

            cout << "Enter Author Name: ";
            cin.getline(b.author, 50);

            cout << "Enter Number of Pages: ";
            cin >> b.pages;

            file.open("library.dat", ios::out |
                      ios::app | ios::binary);

            file.write((char*)&b, sizeof(b));
            file.close();

            cout << "\nBook added successfully!";
        }

        else if (choice == 2)
        {
            cout << "\n1. Search by Title";
            cout << "\n2. Search by Author";
            cout << "\n3. Search by Accession Number";
            cout << "\nEnter choice: ";
            cin >> choice;

            found = false;

            if (choice == 1 || choice == 2)
            {
                cout << "Enter Title/Author: ";
                cin >> ws;
                cin.getline(searchName, 50);
            }
            else if (choice == 3)
            {
                cout << "Enter Accession Number: ";
                cin >> searchCode;
            }
            else
            {
                cout << "Invalid choice!";
                continue;
            }

            file.open("library.dat", ios::in | ios::binary);

            while (file.read((char*)&b, sizeof(b)))
            {
                if ((choice == 1 && strcmp(b.title, searchName) == 0) ||
                    (choice == 2 && strcmp(b.author, searchName) == 0) ||
                    (choice == 3 && b.code == searchCode))
                {
                    cout << "\n----- BOOK DETAILS -----";
                    cout << "\nAccession Number: " << b.code;
                    cout << "\nBook Title: " << b.title;
                    cout << "\nAuthor Name: " << b.author;
                    cout << "\nPages: " << b.pages;

                    found = true;
                }
            }

            if (!found)
                cout << "\nBook not found!";

            file.close();
        }

    } while (choice != 3);

    return 0;
}

