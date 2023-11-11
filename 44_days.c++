// Q1.Minimum Swaps for Bracket Balancing ....

#include <iostream>
#include <stack>

using namespace std;
int minSwapsForBracketBalancing(const std::string& sequence) {
    int n = sequence.length();
    int swaps = 0;
    int imbalance = 0;

    for (int i = 0; i < n; ++i) {
        if (sequence[i] == '(') {
            imbalance++;
        } else {
            imbalance--;
        }

        if (imbalance < 0) {
            swaps++;
            imbalance = 0; 
        }
    }

    return swaps;
}

int main() {
  string sequence = ")(()(";

    int result = minSwapsForBracketBalancing(sequence);

    cout << "Minimum swaps needed: " << result << std::endl;

    return 0;
}


// Q2.Minimum characters to be added at front to make string palindrome....

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCharsToMakePalindrome(const string& str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    string concatStr = str + "#" + revStr;

    vector<int> lps(concatStr.length(), 0);

    for (int i = 1, len = 0; i < concatStr.length(); ) {
        if (concatStr[i] == concatStr[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return str.length() - lps.back();
}

int main() {
    string input = "abacaba";

    int result = minCharsToMakePalindrome(input);

    cout << "Minimum characters to be added at front: " << result << endl;

    return 0;
}
