class Solution {
public:
    vector<int> sortedNums;
    long long ans = 0; // use long long to avoid overflow

    void merge(vector<int>& sortedNums, int s, int m, int e) {
        vector<int> left(sortedNums.begin() + s, sortedNums.begin() + m + 1);
        vector<int> right(sortedNums.begin() + m + 1, sortedNums.begin() + e + 1);

        int i = 0, j = 0, k = s;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j])
                sortedNums[k++] = left[i++];
            else
                sortedNums[k++] = right[j++];
        }
        while (i < left.size()) sortedNums[k++] = left[i++];
        while (j < right.size()) sortedNums[k++] = right[j++];
    }

    void mergeSort(vector<int>& sortedNums, int s, int e) {
        if (s >= e) return;

        int m = s + (e - s) / 2;
        mergeSort(sortedNums, s, m);
        mergeSort(sortedNums, m + 1, e);

        // count reverse pairs
        int j = m + 1;
        for (int i = s; i <= m; i++) {
            while (j <= e && (long long)sortedNums[i] > 2LL * sortedNums[j]) {
                j++;
            }
            ans += (j - (m + 1)); // all elements in right[s..j-1] work for this i
        }

        merge(sortedNums, s, m, e);
    }

    int reversePairs(vector<int>& nums) {
        sortedNums = nums;
        ans = 0;
        mergeSort(sortedNums, 0, nums.size() - 1);
        return (int)ans;
    }
};
