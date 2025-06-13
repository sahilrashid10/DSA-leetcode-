// 1.[x] --> 0
// 2.[1, 2, 8, 6, 4]--->sort
// 3.[1, 2, 4, 6, 8] ---> use binary search
class Solution {
public:
    int n;

    bool helper(vector<int>& nums, int p, int ans) {
        int i = 0;
        while (i < n - 1) {
            if (abs(nums[i] - nums[i + 1]) <= ans) {
                p--;
                i += 2;
            } else
                i++;

            if (p == 0)
                return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        if (n == 1 || p == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums[n - 1] - nums[0];

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (helper(nums, p, mid)) {
                end = mid - 1;
            } else
                start = mid + 1;
        }

        return start;
    }
};

// class Solution {
// public:
//     int ans = INT_MAX;

//     void backtrack(vector<int>& nums, int p, vector<bool>& used, int
//     pairs_formed, int current_max) {
//         if (pairs_formed == p) {
//             ans = min(ans, current_max);
//             return;
//         }

//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             if (used[i]) continue;
//             for (int j = i + 1; j < n; ++j) {
//                 if (used[j]) continue;

//                 // Choose the pair (i, j)
//                 used[i] = used[j] = true;
//                 int diff = abs(nums[i] - nums[j]);

//                 backtrack(nums, p, used, pairs_formed + 1, max(current_max,
//                 diff));

//                 // Backtrack
//                 used[i] = used[j] = false;
//             }
//         }
//     }

//     int minimizeMax(vector<int>& nums, int p) {
//         vector<bool> used(nums.size(), false);
//         backtrack(nums, p, used, 0, 0);
//         return ans;
//     }
// };
