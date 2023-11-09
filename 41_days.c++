//Q1.Edit Distance... 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][n];
}

int main() {
    string word1 = "kitten";
    string word2 = "sitting";

    int distance = minDistance(word1, word2);
    cout << "Edit distance between '" << word1 << "' and '" << word2 << "' is " << distance << endl;

    return 0;
}


// Q2.Next Permutation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3};

    do {
        for (int num : numbers) {
            cout << num << ' ';
        }
        cout << endl;
    } while (next_permutation(numbers.begin(), numbers.end()));

    return 0;
}
