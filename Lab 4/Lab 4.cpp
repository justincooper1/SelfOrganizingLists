#include <iostream>
#include <fstream>
#include <string>
#include "Count.h"
#include "Transpose.h"
#include "MoveToFront.h"

using namespace std;

void testCharacters() {
    Count<char> countList;
    Transpose<char> transposeList;
    MoveToFront<char> mtfList;

    // Building initial list
    char initialChars[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    for (char c : initialChars) {
        countList.addIt(c);
        transposeList.addIt(c);
        mtfList.addIt(c);
    }

    // Searching for characters
    char searchChars[] = { 'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I' };
    for (char c : searchChars) {
        countList.search(c);
        transposeList.search(c);
        mtfList.search(c);
    }

    // Print final list and number of compares
    countList.printlist();
    mtfList.printlist();

    cout << endl;
    transposeList.printlist();

    cout << endl;
}

void testStrings() {
    Count<string> countList;
    Transpose<string> transposeList;
    MoveToFront<string> mtfList;

    // Open and read test.txt file
    ifstream infile("test.txt");
    string word;
    while (infile >> word) {
        countList.search(word);
        mtfList.search(word);
        transposeList.search(word);
    }

    countList.printlist(10);
    cout << endl;
    mtfList.printlist(10);
    cout << endl;
    transposeList.printlist(10);

    cout << endl;
}

int main() {
    cout << "Running character test:" << endl << endl;
    testCharacters();

    cout << "\nRunning string test";
    testStrings();

    return 0;
}