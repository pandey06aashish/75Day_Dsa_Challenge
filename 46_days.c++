//Q1. Min Number of Flips ...

#include <iostream>
#include <algorithm>

using namespace std;

int minFlipsToMakeAlternating(const string& s) {
    int n = s.size();

    int flipsStartWithZero = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '0' + i % 2) {
            flipsStartWithZero++;
        }
    }

    int flipsStartWithOne = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '0' + (1 - i % 2)) {
            flipsStartWithOne++;
        }
    }

    return min(flipsStartWithZero, flipsStartWithOne);
}

int main() {
    string binaryString;
    cout << "Enter a binary string: ";
    cin >> binaryString;

    int minFlips = minFlipsToMakeAlternating(binaryString);
    cout << "Minimum number of flips needed: " << minFlips << endl;

    return 0;
}

// Q2.Longest Common Subsequence....

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;

    cout << "Enter the first sequence: ";
    cin >> str1;

    cout << "Enter the second sequence: ";
    cin >> str2;

    int lcsLength = longestCommonSubsequence(str1, str2);

    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}

