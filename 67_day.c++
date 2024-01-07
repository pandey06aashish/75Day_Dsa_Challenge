// Q1.The Celebrity Problem..
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool check_a_know_b(vector<vector<int>> v, int a, int b, int n) {
    return v[a][b] == 1;
}

int check_celebrity(vector<vector<int>> v, int n) {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (check_a_know_b(v, a, b, n)) {
            s.push(b);
        }
        else {
            s.push(a);
        }
    }

    int candidate = s.top();

    for (int i = 0; i < n; i++) {
        if (i != candidate && (v[candidate][i] == 1 || v[i][candidate] == 0)) {
            return -1;
        }
    }

    return candidate;
}

int main() {
    vector<vector<int>> v = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int n = 3;
    cout << check_celebrity(v, n);
    return 0;
}

