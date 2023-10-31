//Q1. Median in a row-wise sorted Matrix..

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMedian(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int min_val = INT8_MIN;
    int max_val = INT8_MAX;

    for (int i = 0; i < rows; i++) {
        min_val = min(min_val, matrix[i][0]);
        max_val = max(max_val, matrix[i][cols - 1]);
    }

    while (min_val < max_val) {
        int mid = min_val + (max_val - min_val) / 2;
        int count = 0;

        for (int i = 0; i < rows; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (count < (rows * cols) / 2 + 1) {
            min_val = mid + 1;
        } else {
            max_val = mid;
        }
    }

    return min_val;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int median = findMedian(matrix);
    cout << "Median: " << median << endl;

    return 0;
}

// Q2.Find a specific pair in Matrix..

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findSpecificPair(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == target) {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int target = 5;

    pair<int, int> result = findSpecificPair(matrix, target);

    if (result.first != -1) {
        cout << "Pair " << target << " found at row " << result.first << " and column " << result.second << endl;
    } else {
        cout << "Pair " << target << " not found in the matrix." << endl;
    }

    return 0;
}
