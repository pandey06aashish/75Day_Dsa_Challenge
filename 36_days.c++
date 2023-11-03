// Q1.Print all the duplicate characters in a string ...
#include <iostream>
#include <string>

using namespace std;

int main() {
    string inputString;
    cout << "Enter a string: ";
    cin >> inputString;

    const int numChars = 256; 

    int charCount[numChars] = {0};

    for (char c : inputString) {
        if (isalpha(c)) {
            charCount[static_cast<int>(c)]++;
        }
    }

    bool foundDuplicates = false;

    for (char c : inputString) {
        if (isalpha(c) && charCount[static_cast<int>(c)] > 1) {
            if (!foundDuplicates) {
                cout << "Duplicate characters: ";
                foundDuplicates = true;
            }
            cout << c << " ";
            charCount[static_cast<int>(c)] = 0;
        }
    }

    if (!foundDuplicates) {
        cout << "No duplicate characters found.";
    }

    cout << endl;

    return 0;
}


// Q2.Check if given strings are rotations of each other or not...

#include <iostream>
#include <string>

using namespace std; 

bool areRotations(const string& str1, const string& str2) {
    if (str1.length() != str2.length() || str1.empty()) {
        return false;
    }

    string concatenated = str1 + str1;

    return concatenated.find(str2) != string::npos;
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    if (areRotations(str1, str2)) {
        cout << "The strings are rotations of each other." << endl;
    } else {
        cout << "The strings are not rotations of each other." << endl;
    }

    return 0;
}
