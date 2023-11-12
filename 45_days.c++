// Q1.Boyer Moore Algorithm for Pattern Searching....
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 256;

void computeBadCharacterHeuristic(const string& pattern, vector<int>& badChar) {
    int m = pattern.length();
    badChar.resize(ALPHABET_SIZE, -1);

    for (int i = 0; i < m; ++i) {
        badChar[static_cast<int>(pattern[i])] = i;
    }
}

void searchBoyerMoore(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> badChar;
    computeBadCharacterHeuristic(pattern, badChar);

    int s = 0;  

    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Pattern found at index " << s << endl;
            
            s += (s + m < n) ? m - badChar[static_cast<int>(text[s + m])] : 1;
        } else {
            s += max(1, j - badChar[static_cast<int>(text[s + j])]);
        }
    }
}

int main() {
    string text = "ABAAABCD";
    string pattern = "ABC";
    
    searchBoyerMoore(text, pattern);

    return 0;
}


// Q2.Roman Number to Integer...

#include <iostream>
#include <string>

using namespace std;

int romanToInt(string s) {
    int result = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (i < s.length() - 1 && getValue(s[i]) < getValue(s[i + 1])) {
            result -= getValue(s[i]);
        } else {
            result += getValue(s[i]);
        }
    }

    return result;
}

int getValue(char romanChar) {
    switch (romanChar) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    string romanNumeral = "IX";

    int result = romanToInt(romanNumeral);

    cout << "The integer representation of " << romanNumeral << " is: " << result << endl;

    return 0;
}
