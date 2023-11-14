//Q1.First and last occurrences of x 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 2, 5, 2, 6, 7};

    int x = 2; 
    auto firstOccurrence = find(vec.begin(), vec.end(), x);

    auto lastOccurrence = find_end(vec.begin(), vec.end(), &x, &x + 1);

    if (firstOccurrence != vec.end()) {
        cout << "First occurrence of " << x << " at index: " << distance(vec.begin(), firstOccurrence) << endl;
    } else {
        cout << "Element " << x << " not found." << endl;
    }

    if (lastOccurrence != vec.end()) {
        cout << "Last occurrence of " << x << " at index: " << distance(vec.begin(), lastOccurrence) << endl;
    } else {
        cout << "Element " << x << " not found." << endl;
    }

    return 0;
}

// Q2.Value equal to index value....

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Elements equal to their index values:" << endl;

    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == static_cast<int>(i)) {
            cout << "Index: " << i << ", Value: " << vec[i] << endl;
        }
    }

    return 0;
}


