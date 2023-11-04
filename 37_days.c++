// Q1.Longest Repeating Subsequence...

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestRepeatingSubsequence(string str) {
    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i - 1] == str[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[n][n];
    string result = "";

    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (str[i - 1] == str[j - 1] && i != j) {
            result = str[i - 1] + result;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return result;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string longestRepeatingSeq = longestRepeatingSubsequence(str);
    cout << "Longest Repeating Subsequence: " << longestRepeatingSeq << endl;

    return 0;
}

// Q2.

// 