//									  Object Oriented Programming [MCA 4121] IA-3: Take Home Assignment

/*
Create a file article.txt and store a paragraph of text in it. You need to analyse the frequency of certain important terms in the document.
You are provided with a file called keywords.txt that contains the key terms to track (one term per line).
Write a C++ program to perform the following operations:
	1. Count how many times each word from keywords.txt appears in article.txt
	2. Store the counts in a file named keyword_frequency.txt, where each line contains the keyword and its corresponding frequency.
	3. Identify the most frequently occurring keyword and print it to the console.
*/

// Count keyword occurrences in an article using text files.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Get a paragraph from the user and save it in article.txt.
void createArticleFile(){
    ofstream file("article.txt");
    string line;
    cout << "Enter the article paragraph. Press Enter on a blank line to finish:\n";
    while (getline(cin, line)){
        if (line.empty())
            break;
        file << line << endl;
    }
    file.close();
}

// Get one keyword per line and save them in keywords.txt.
void createKeywordsFile(){
    ofstream file("keywords.txt");
    string keyword;
    cout << "\nEnter keywords one per line (single words). Press Enter on a blank line to finish:\n";
    while (getline(cin, keyword)){
        if (keyword.empty())
            break;
        file << keyword << endl;
    }
    file.close();
}

// Read keywords from keywords.txt and convert them to lowercase.
int readKeywords(string keywords[], int maxSize){
    ifstream file("keywords.txt");
    int n = 0;
    while (n < maxSize && file >> keywords[n]){
        for (int i = 0; i < (int)keywords[n].length(); i++)
            keywords[n][i] = tolower((unsigned char)keywords[n][i]);
        n++;
    }
    file.close();
    return n;
}

// Compare a word with the keywords and increase its frequency.
void countWord(string word, string keywords[], int frequency[], int n){
    for (int i = 0; i < n; i++){
        if (word == keywords[i])
            frequency[i]++;
    }
}

// Read article.txt and count complete-word matches.
void readArticle(string keywords[], int frequency[], int n){
    ifstream file("article.txt");
    string word = "";
    char ch;
    while (file.get(ch)){
        if (isalnum((unsigned char)ch))
            word += tolower((unsigned char)ch);
        else{
            countWord(word, keywords, frequency, n);
            word = "";
        }
    }
    countWord(word, keywords, frequency, n); // Count the final word.
    file.close();
}

// Save every keyword and its frequency in keyword_frequency.txt.
void writeResults(string keywords[], int frequency[], int n){
    ofstream file("keyword_frequency.txt");
    for (int i = 0; i < n; i++)
        file << keywords[i] << " : " << frequency[i] << endl;
    file.close();
}

// Read and display the paragraph saved in article.txt.
void displayArticle(){
    ifstream file("article.txt");
    string line;
    cout << "\nEntered Paragraph:\n";
    while (getline(file, line))
        cout << line << endl;
    file.close();
}

// Read and display the output file on the screen.
void displayFile(){
    ifstream file("keyword_frequency.txt");
    string line;
    cout << "\nKeyword Frequencies:\n";
    while (getline(file, line))
        cout << line << endl;
    file.close();
}

int main(){
    string keywords[100];
    int frequency[100] = {0};
    createArticleFile();
    createKeywordsFile();
    int n = readKeywords(keywords, 100);
    if (n == 0){
        cout << "No keywords entered. Please run the program again.\n";
        return 1;
    }
    readArticle(keywords, frequency, n);
    writeResults(keywords, frequency, n);
    // Display the entered paragraph first, followed by the results.
    displayArticle();
    displayFile();
    int maxIndex = 0;
    for (int i = 1; i < n; i++){
        if (frequency[i] > frequency[maxIndex])
            maxIndex = i;
    }
    if (frequency[maxIndex] > 0)
        cout << "\nMost frequently occurring keyword: " << keywords[maxIndex]
             << " (" << frequency[maxIndex] << " times)\n";
    else
        cout << "\nNone of the keywords was found in article.txt.\n";
    return 0;
}

/*
OUTPUT:

Enter the article paragraph. Press Enter on a blank line to finish:
Artificial intelligence is changing software development.
Artificial intelligence tools can help programmers write code, test code, review code, and improve code.
However, programmers must review the code carefully.
Good software needs clear design, testing, and documentation.
Artificial intelligence can support programmers, but human understanding remains important.


Enter keywords one per line (single words). Press Enter on a blank line to finish:
artificial
intelligence
code
programmers
software
testing
data


Entered Paragraph:
Artificial intelligence is changing software development.
Artificial intelligence tools can help programmers write code, test code, review code, and improve code.
However, programmers must review the code carefully.
Good software needs clear design, testing, and documentation.
Artificial intelligence can support programmers, but human understanding remains important.

Keyword Frequencies:
artificial : 3
intelligence : 3
code : 5
programmers : 3
software : 2
testing : 1
data : 0

Most frequently occurring keyword: code (5 times)

*/
