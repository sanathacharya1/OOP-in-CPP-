
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    ifstream file("log.txt");

    if (!file) {
        cout << "Unable to open file!";
        return 0;
    }

    int characters = 0;
    int letters = 0;
    int digits = 0;
    int whitespace = 0;
    int words = 0;
    int lines = 0;
    int occurrences = 0;

    char ch, searchChar;
    bool inWord = false;

    cout << "Enter character to search: ";
    cin >> searchChar;

    // Read the file character by character
    while (file.get(ch)) {
        characters++;

        if (isalpha((unsigned char)ch))
            letters++;

        if (isdigit((unsigned char)ch))
            digits++;

        if (isspace((unsigned char)ch))
            whitespace++;

        // Count words
        if (!isspace((unsigned char)ch)) {
            if (!inWord) {
                words++;
                inWord = true;
            }
        }
        else {
            inWord = false;
        }

        // Count lines
        if (ch == '\n')
            lines++;

        // Count character without case sensitivity
        if (tolower((unsigned char)ch) ==
            tolower((unsigned char)searchChar)) {
            occurrences++;
        }
    }

    // Count the last line if it does not end with newline
    if (characters > 0 && ch != '\n')
        lines++;

    cout << "\n----- LOG FILE ANALYSIS -----";
    cout << "\nTotal Characters: " << characters;
    cout << "\nTotal Letters: " << letters;
    cout << "\nTotal Digits: " << digits;
    cout << "\nTotal Whitespace: " << whitespace;
    cout << "\nTotal Words: " << words;
    cout << "\nTotal Lines: " << lines;
    cout << "\nOccurrences of '" << searchChar
         << "': " << occurrences;

    file.close();

    return 0;
}

