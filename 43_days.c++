// Q1.Count the Reversals...

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int countReversals(const string& expression) {
    int length = expression.length();

    if (length % 2 != 0) {
        return -1;
    }

    stack<char> s;

    for (int i = 0; i < length; ++i) {
        char currentChar = expression[i];

        if (currentChar == '{') {
            s.push(currentChar);
        }
        else if (currentChar == '}') {
            if (!s.empty() && s.top() == '{') {
                s.pop();
            }
            else {
                s.push(currentChar);
            }
        }
    }

    int unbalancedCount = s.size();
    int reversalsCount = 0;

    while (!s.empty()) {
        char top = s.top();
        s.pop();

        char bottom = s.top();
        s.pop();

        if (top != bottom) {
            reversalsCount += 2;
        }

        else {
            reversalsCount += 1;
        }
    }

    return reversalsCount;
}

int main() {
    string expression;
    
    cout << "Enter a string of curly brackets: ";
    cin >> expression;

    int result = countReversals(expression);

    if (result == -1) {
        cout << "The expression has an odd number of characters, so it cannot be balanced." << endl;
    } else {
        cout << "Minimum number of reversals needed: " << result << endl;
    }

    return 0;
}

// Q2.Count Palindromic Subsequences...

#include <iostream>
#include <cstring>

using namespace std;

int countPalindromicSubsequences(const string& s) {
    int n = s.length();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s;
    
    cout << "Enter a string: ";
    cin >> s;

    int result = countPalindromicSubsequences(s);

    cout << "Number of palindromic subsequences: " << result << endl;

    return 0;
}

