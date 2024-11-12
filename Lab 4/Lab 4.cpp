#include <iostream>
#include <fstream>
#include <string>
#include "Count.h"
using namespace std;

void testCharacters() {
    Count<char> countList;

    // Building initial list
    char initialChars[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    for (char c : initialChars) {
        countList.addIt(c);
    }

    // Searching for characters
    char searchChars[] = { 'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I' };
    for (char c : searchChars) {
        countList.search(c);
    }

    // Print final list and number of compares
    countList.printlist();
}

void testStrings() {
    Count<string> countList;

    // Open and read test.txt file
    ifstream infile("test.txt");
    string word;
    while (infile >> word) {
        countList.search(word);
    }

    countList.printlist(10);
    cout << endl;
}

int main() {
    cout << "Running character test:" << endl << endl;
    testCharacters();

    cout << "\nRunning string test";
    testStrings();

    return 0;
}