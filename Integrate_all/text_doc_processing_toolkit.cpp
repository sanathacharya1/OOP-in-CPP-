#include<bits/stdc++.h>
using namespace std;

// 1. Create a text file
void createFile()
{
    ofstream file("document.txt");

    if (!file)
    {
        cout << "File cannot be created!\n";
        return;
    }

    string line;

    cout << "\nEnter document content.";
    cout << "\nEnter END on a separate line to finish.\n";

    cin.ignore();

    while (true)
    {
        getline(cin, line);

        if (line == "END")
            break;

        file << line << '\n';
    }

    file.close();

    cout << "Document created successfully!\n";
}

// 2. Display file content
void displayFile()
{
    ifstream file("document.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    string line;

    cout << "\n----- DOCUMENT CONTENT -----\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// 3. Count words, lines, letters, digits, spaces and special characters
void countCharacters()
{
    ifstream file("document.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    string line;
    int words = 0, lines = 0;
    int letters = 0, digits = 0;
    int spaces = 0, special = 0;
    bool inWord = false;

    while (getline(file, line))
    {
        lines++;

        for (int i = 0; i < line.length(); i++)
        {
            char ch = line[i];

            if (isalpha((unsigned char)ch))
                letters++;

            else if (isdigit((unsigned char)ch))
                digits++;

            else if (ch == ' ')
                spaces++;

            else if (!isspace((unsigned char)ch))
                special++;

            // Count a word only when entering a new word
            if (isspace((unsigned char)ch))
            {
                inWord = false;
            }
            else if (!inWord)
            {
                words++;
                inWord = true;
            }
        }

        // New line separates words
        inWord = false;
    }

    cout << "\n----- DOCUMENT STATISTICS -----\n";
    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Special Characters: " << special << endl;

    file.close();
}

// 4. Convert lowercase to uppercase and vice versa
void toggleCase()
{
    ifstream file("document.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    ofstream output("converted.txt");

    if (!output)
    {
        cout << "Output file cannot be created!\n";
        file.close();
        return;
    }

    char ch;

    while (file.get(ch))
    {
        if (islower((unsigned char)ch))
            ch = toupper((unsigned char)ch);

        else if (isupper((unsigned char)ch))
            ch = tolower((unsigned char)ch);

        output.put(ch);
    }

    file.close();
    output.close();

    cout << "Case converted successfully!\n";
    cout << "Result stored in converted.txt\n";
}

// 5. Copy file while removing repeated spaces
void removeExtraSpaces()
{
    ifstream file("document.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    ofstream output("cleaned.txt");

    if (!output)
    {
        cout << "Output file cannot be created!\n";
        file.close();
        return;
    }

    char ch;
    bool previousSpace = false;

    while (file.get(ch))
    {
        if (ch == ' ')
        {
            if (!previousSpace)
                output.put(ch);

            previousSpace = true;
        }
        else
        {
            output.put(ch);
            previousSpace = false;
        }
    }

    file.close();
    output.close();

    cout << "File copied with repeated spaces removed!\n";
    cout << "Result stored in cleaned.txt\n";
}

// 6. Identify palindromic words
void findPalindromes()
{
    ifstream file("document.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    string line, word;
    bool found = false;

    cout << "\n----- PALINDROMIC WORDS -----\n";

    while (getline(file, line))
    {
        stringstream ss(line);

        while (ss >> word)
        {
            string clean = "";

            // Remove punctuation and convert to lowercase
            for (int i = 0; i < word.length(); i++)
            {
                if (isalnum((unsigned char)word[i]))
                {
                    clean += tolower((unsigned char)word[i]);
                }
            }

            string reverseWord = clean;

            // Reverse the cleaned word
            int left = 0;
            int right = reverseWord.length() - 1;

            while (left < right)
            {
                swap(reverseWord[left], reverseWord[right]);
                left++;
                right--;
            }

            if (clean.length() > 1 && clean == reverseWord)
            {
                cout << clean << endl;
                found = true;
            }
        }
    }

    if (!found)
        cout << "No palindrome words found!\n";

    file.close();
}

// 7. Encrypt or decrypt using a shift key
void encryptDecrypt()
{
    int choice, key;

    cout << "\n1. Encrypt";
    cout << "\n2. Decrypt";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice != 1 && choice != 2)
    {
        cout << "Invalid choice!\n";
        return;
    }

    cout << "Enter shift key: ";
    cin >> key;

    key = key % 26;

    if (choice == 2)
        key = -key;

    ifstream file("document.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    ofstream output;

    if (choice == 1)
        output.open("encrypted.txt");
    else
        output.open("decrypted.txt");

    if (!output)
    {
        cout << "Output file cannot be created!\n";
        file.close();
        return;
    }

    char ch;

    while (file.get(ch))
    {
        if (isupper((unsigned char)ch))
        {
            ch = 'A' + (ch - 'A' + key + 26) % 26;
        }
        else if (islower((unsigned char)ch))
        {
            ch = 'a' + (ch - 'a' + key + 26) % 26;
        }

        output.put(ch);
    }

    file.close();
    output.close();

    if (choice == 1)
        cout << "Encrypted file created: encrypted.txt\n";
    else
        cout << "Decrypted file created: decrypted.txt\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== TEXT PROCESSING TOOLKIT =====";
        cout << "\n1. Create Document";
        cout << "\n2. Display Document";
        cout << "\n3. Count Words, Lines and Characters";
        cout << "\n4. Convert Case";
        cout << "\n5. Remove Repeated Spaces";
        cout << "\n6. Find Palindromic Words";
        cout << "\n7. Encrypt / Decrypt";
        cout << "\n8. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                createFile();
                break;

            case 2:
                displayFile();
                break;

            case 3:
                countCharacters();
                break;

            case 4:
                toggleCase();
                break;

            case 5:
                removeExtraSpaces();
                break;

            case 6:
                findPalindromes();
                break;

            case 7:
                encryptDecrypt();
                break;

            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}
