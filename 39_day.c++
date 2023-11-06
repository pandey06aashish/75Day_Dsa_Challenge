// Q1.Edit Distance ....
#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int editDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string word1 = "kitten";
    string word2 = "sitting";

    int distance = editDistance(word1, word2);
    cout << "Edit distance between '" << word1 << "' and '" << word2 << "' is: " << distance << endl;

    return 0;
}

// Q2.Parenthesis Checker...

#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& str) {
    std::stack<char> stack;

    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.empty()) {
                return false; 
            }

            char top = stack.top();
            stack.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    std::string input;
    std::cout << "Enter a string with parentheses: ";
    std::cin >> input;

    if (isBalanced(input)) {
        std::cout << "The parentheses are balanced." << std::endl;
    } else {
        std::cout << "The parentheses are not balanced." << std::endl;
    }

    return 0;
}
