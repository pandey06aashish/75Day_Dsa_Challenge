// Q1.Count Inversions...

#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int l = left; l <= right; l++) {
        arr[l] = temp[l];
    }

    return invCount;
}

long long mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        invCount += mergeAndCount(arr, temp, left, mid, right);
    }

    return invCount;
}

long long countInversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};
    cout << "Number of inversions: " << countInversions(arr) << endl;

    return 0;
}


//Q2. SUBSUMS - Subset Sums...

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> calculateSubsetSums(const vector<int>& set, int start, int end) {
    int n = end - start + 1;
    vector<int> subsetSums;

    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += set[start + i];
            }
        }
        subsetSums.push_back(sum);
    }

    return subsetSums;
}

int countSubsets(const vector<int>& set, int L, int R) {
    int n = set.size();
    int mid = n / 2;

    vector<int> subsetSums1 = calculateSubsetSums(set, 0, mid - 1);
    vector<int> subsetSums2 = calculateSubsetSums(set, mid, n - 1);

    sort(subsetSums2.begin(), subsetSums2.end());

    int count = 0;

    for (int sum : subsetSums1) {
        count += upper_bound(subsetSums2.begin(), subsetSums2.end(), R - sum) -
                 lower_bound(subsetSums2.begin(), subsetSums2.end(), L - sum);
    }

    return count;
}

int main() {
    int N, L, R;
    cin >> N >> L >> R;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int result = countSubsets(A, L, R);
    cout << result << endl;

    return 0;
}
