class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        long long even = 0, odd = 0;

        for(int i=1; i<n+1; i++){
            // 0 - even, 1-odd
            odd = max(even - nums[i-1], odd);
            even = max(odd + nums[i-1], even);
        }
        return max(even, odd);
    }
};
// class Solution {
// public:
//     long long maxAlternatingSum(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return nums[0];

//         vector<vector<long long>> dp(n+1, vector<long long>(2, 0));

//         for(int i=1; i<n+1; i++){
//             // 0 - even, 1-odd
//             dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]);
//             dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]);
//         }
//         return max(dp[n][0], dp[n][1]);
//     }
// };
// class Solution {
// public:
//     int n;
//     long long t[100000][2];
//     long long solve(vector<int>& nums, int i, bool flag){
//         if(i >= n) return 0;


//         if(t[i][flag] != -1){
//             return t[i][flag];
//         }
//         long long skip = solve(nums, i+1, flag);
//         int val = nums[i];

//         if(flag) val = -val;

//         long long take = val + solve(nums, i+1, !flag);

//         return t[i][flag] = max(take, skip);
//     }
//     long long maxAlternatingSum(vector<int>& nums) {
//         n = nums.size();
//         memset(t, -1, sizeof(t));
//         if(n==1) return nums[0];

//         long long ans = solve(nums, 0, false);
//         return ans;
//     }
// };