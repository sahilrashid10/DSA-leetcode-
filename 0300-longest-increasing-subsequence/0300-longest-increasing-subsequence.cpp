class Solution {
public:

    int t[2500][2500];
    int solve(vector<int>& nums, int i, int prev){
        //base case

        if(i >= nums.size() )
            return 0;

        if(prev != -1 && t[i][prev] != -1) return t[i][prev];
        int take = 0;
        //pruning
        if(prev == -1 || nums[i] > nums[prev])
            take = 1 + solve(nums, i+1, i);

        int skip = solve(nums, i+1, prev);

        if(prev!= -1)
            t[i][prev] = max(take, skip);
        
        return  max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int ans = solve(nums, 0, -1);
        return ans;
    }
};
// BOTTOM UP
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return 1;

//         vector<int> dp(n, 1);
//         int maxi = 1;
//         for(int i=1; i<n; i++){
//             int j = 0;
//             while(j < i){
//                 if(nums[j] < nums[i]){
//                     dp[i] = max(dp[j] + 1, dp[i]);
//                     maxi = max(dp[i], maxi);
//                 }
//                 j++;
//             }
//         }
//         return maxi; 
//     }
// };
//time O(n^2) space O(n^2)
// class Solution {
// public:

//     int t[2500][2500];
//     int solve(vector<int>& nums, int i, int prev){
//         //base case

//         if(i >= nums.size() )
//             return 0;

//         if(prev != -1 && t[i][prev] != -1) return t[i][prev];
//         int take = 0;
//         //pruning
//         if(prev == -1 || nums[i] > nums[prev])
//             take = 1 + solve(nums, i+1, i);

//         int skip = solve(nums, i+1, prev);

//         if(prev!= -1)
//             t[i][prev] = max(take, skip);
        
//         return  max(take, skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         memset(t, -1, sizeof(t));
//         int ans = solve(nums, 0, -1);
//         return ans;
//     }
// };