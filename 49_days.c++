// Q1.Transform One String to Another using Minimum Number of Given Operation....

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperations(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min({ dp[i][j - 1], 
                                    dp[i - 1][j],  
                                    dp[i - 1][j - 1] 
                                  });
        }
    }

    return dp[m][n];
}

int main() {
    string str1 = "kitten";
    string str2 = "sitting";

    cout << "Minimum number of operations: " << minOperations(str1, str2) << endl;

    return 0;
}

// Q2.Wildcard string matching...

#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string text, string pattern) {
    int m = text.length();
    int n = pattern.length();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;

    for (int j = 1; j <= n; ++j) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (pattern[j - 1] == '?' || text[i - 1] == pattern[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string text = "aa";
    string pattern = "a*";

    if (isMatch(text, pattern)) {
        cout << "The text matches the pattern." << endl;
    } else {
        cout << "The text does not match the pattern." << endl;
    }

    return 0;
}
