//OPTIMAL APPROACH
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int temp = *max_element(nums.begin(), nums.end());
        if (temp < 0) return temp;
        
        int n = nums.size();
        map<int, long long> mp;  // Stores the max sum for given key (nums[i] - i)

        long long result = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            auto it = mp.upper_bound(nums[i] - i);
            
            long long maxi = nums[i];
            if (it != mp.begin()) {
                it--;
                maxi += it->second;
            }

            mp[nums[i] - i] = max(mp[nums[i] - i], maxi);

            it = mp.upper_bound(nums[i] - i);
            while (it != mp.end() && it->second <= maxi) {
                it = mp.erase(it);
            }

            result = max(result, mp[nums[i] - i]);
        }
        return result;
    }
};

// BOTTOM UP 
// class Solution {
// public:
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         // If all numbers are negative, return the maximum element.
//         int ans = *max_element(nums.begin(), nums.end());
//         if(ans < 0) return ans;
        
//         int n = nums.size();
//         vector<long long> dp(n);
        
//         // Initialize dp[i] with nums[i].
//         for (int i = 0; i < n; i++) {
//             dp[i] = nums[i];
//         }
        
//         long long maxSum = LLONG_MIN;
//         // Calculate maximum balanced subsequence sum ending at each index.
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[i] - i >= nums[j] - j) {
//                     dp[i] = max(dp[i], dp[j] + nums[i]);
//                 }
//             }
//             maxSum = max(maxSum, dp[i]);
//         }
//         return maxSum;
//     }
// };

//MEMOISED
// class Solution {
// public:
//     vector<vector<long long>> dp;  // Memoization table

//     long long solve(vector<int>& nums, int i, int prev) {
//         if (i >= nums.size()) return 0;

//         if (dp[i][prev + 1] != LLONG_MIN) return dp[i][prev + 1];

//         long long take = LLONG_MIN;
//         if (prev == -1 || (nums[i] - i >= nums[prev] - prev))
//             take = nums[i] + solve(nums, i + 1, i);

//         long long skip = solve(nums, i + 1, prev);

//         return dp[i][prev + 1] = max(take, skip);
//     }

//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int ans = *max_element(nums.begin(), nums.end());
//         if (ans < 0) return ans;

//         int n = nums.size();
//         dp.assign(n, vector<long long>(n + 1, LLONG_MIN));  // Initialize memo table

//         return solve(nums, 0, -1);
//     }
// };
