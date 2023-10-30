// Q1.Row with max 1s....

#include <iostream>
#include <vector>
using namespace std;

int findRowWithMaxOnes(const vector<vector<int>>& matrix) {
    int maxOnes = 0;
    int maxRow = -1;

    for (int i = 0; i < matrix.size(); i++) {
        int onesCount = 0;
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                onesCount++;
            }
        }

        if (onesCount > maxOnes) {
            maxOnes = onesCount;
            maxRow = i;
        }
    }

    return maxRow;
}

int main() {
    vector<vector<int>> matrix = {{0, 1, 1, 1},{0, 0, 1, 1},{1, 1, 1, 1},{0, 0, 0, 1} };

    int maxRow = findRowWithMaxOnes(matrix);

    if (maxRow != -1) {
        cout << "The row with the maximum number of 1s is row " << maxRow << endl;
    } else {
        cout << "No row with 1s found." << endl;
    }

    return 0;
}


// Q2.Sorted matrix.....

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const vector<int>& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> sortedMatrix = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};

    cout << "Sorted Matrix:" << endl;
    printMatrix(sortedMatrix);

    sortedMatrix[1][2] = 42;

    cout << "Modified Matrix:" << endl;
    printMatrix(sortedMatrix);

    return 0;
}

