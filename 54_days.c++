// Q1.Weighted Job Scheduling in O(n Log n) time....

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
    int start, finish, profit;
};

bool jobComparataor(Job a, Job b) {
    return (a.finish < b.finish);
}

int latestNonConflict(vector<Job>& jobs, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (jobs[j].finish <= jobs[i].start) {
            return j;
        }
    }
    return -1;
}

int weightedJobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), jobComparataor);

    vector<int> dp(jobs.size());

    // Base case
    dp[0] = jobs[0].profit;

    for (int i = 1; i < jobs.size(); i++) {
        int index = latestNonConflict(jobs, i);

        int inclProf = (index != -1) ? dp[index] + jobs[i].profit : jobs[i].profit;
        int exclProf = dp[i - 1];

        dp[i] = max(inclProf, exclProf);
    }

    return dp[jobs.size() - 1];
}

int main() {
    vector<Job> jobs = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}, {7, 9, 2}};

    int maxProfit = weightedJobScheduling(jobs);

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}

// Q2.K-th element of two Arrays....

#include <iostream>
#include <vector>

using namespace std;

int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            if (--k == 0) return nums1[i];
            i++;
        } else {
            if (--k == 0) return nums2[j];
            j++;
        }
    }

    while (i < nums1.size()) {
        if (--k == 0) return nums1[i];
        i++;
    }

    while (j < nums2.size()) {
        if (--k == 0) return nums2[j];
        j++;
    }

    return -1;
}

int main() {
    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 6, 8, 10};

    int k = 5;
    int result = kthElement(nums1, nums2, k);

    cout << "K-th element: " << result << endl;

    return 0;
}
