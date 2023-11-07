// Q1.Longest Common Subsequence...

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

   
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs = text1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string text1 = "AGGTAB";
    string text2 = "GXTXAYB";

    string lcs = longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}

// Q2.Program to generate all possible valid IP addresses from given string...

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidPart(const string& part) {
    int num = stoi(part);
    return to_string(num) == part && num >= 0 && num <= 255;
}

void generateIPAddresses(string s, int index, int partNum, string current, vector<string>& validIPs) {
    if (index == s.length() && partNum == 4) {
        validIPs.push_back(current);
        return;
    }

    if (index == s.length() || partNum == 4) {
        return;
    }

    for (int len = 1; len <= 3 && index + len <= s.length(); len++) {
        string part = s.substr(index, len);
        if (isValidPart(part)) {
            if (partNum < 3) {
                generateIPAddresses(s, index + len, partNum + 1, current + part + ".", validIPs);
            } else {
                generateIPAddresses(s, index + len, partNum + 1, current + part, validIPs);
            }
        }
    }
}

vector<string> restoreIPAddresses(string s) {
    vector<string> validIPs;
    generateIPAddresses(s, 0, 0, "", validIPs);
    return validIPs;
}

int main() {
    string input = "25525511135";
    vector<string> validIPs = restoreIPAddresses(input);

    for (const string& ip : validIPs) {
        cout << ip << endl;
    }

    return 0;
}
