// Q1.Word Break...

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input = "Hello, this is a sample sentence.";
    
    istringstream iss(input);
    string word;
    
    while (iss >> word) {
        cout << word << endl;
    }
    
    return 0;
}

// Q2.Rabin-Karp Algorithm for Pattern Searching...

#include <iostream>
#include <string>

const int prime = 101; 
using namespace std;

void searchRabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = 0; 
    int windowHash = 0; 

    for (int i = 0; i < m; i++) {
        patternHash = (patternHash + pattern[i]) % prime;
        windowHash = (windowHash + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (windowHash == patternHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at position " << i << endl;
            }
        }

        if (i < n - m) {
            windowHash = (windowHash - text[i] + text[i + m]) % prime;
            if (windowHash < 0) {
                windowHash += prime; 
            }
        }
    }
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    searchRabinKarp(text, pattern);

    return 0;
}
