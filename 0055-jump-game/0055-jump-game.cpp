class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxReach = nums[0];
        for(int i=1; i<nums.size()-1; i++){
            if(maxReach >= i)
                maxReach = max(maxReach, i + nums[i]);
        }
        
        return maxReach >= nums.size()-1;
    }
};
/*  O(n^2) time, O(n) space*/

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n);
//         dp[0] = true;

//         for(int i=1; i<n; i++){
//             int k = i - 1;
//             while(k >=0){
//                 if(dp[k] == true && k + nums[k] >= i){
//                     dp[i] = true;
//                     break;
//                 }
//                 k--;
//             }
//         }
//         return dp[n-1];
//     }
// };

/*  O(n^2) time, O(n) space*/
// class Solution {
// public:
//     int n;
//     vector<int> dp;
//     bool solve(vector<int>& nums, int i){
//         if(i == n-1)    return true;
//         if(i >= n || nums[i] == 0)  return false;
        
//         if(dp[i] != -1) return dp[i];

//         for(int k = 1; k <= nums[i]; k++){
//             if(solve(nums, i+k))    return dp[i] = true;
//         }
//         return dp[i] = false;
//     }
//     bool canJump(vector<int>& nums) {
//         n = nums.size();
//         dp.resize(n, -1);
//         return solve(nums, 0);
//     }
// };
/*  O(k^n) time, O(n) space*/
// class Solution {
// public:
//     int n;
//     bool solve(vector<int>& nums, int i){
//         if(i == n-1)    return true;
//         if(i >= n || nums[i] == 0)  return false;

//         for(int k = 1; k <= nums[i]; k++){
//             if(solve(nums, i+k))    return true;
//         }
//         return false;
//     }
//     bool canJump(vector<int>& nums) {
//         n = nums.size();
//         return solve(nums, 0);
//     }
// };