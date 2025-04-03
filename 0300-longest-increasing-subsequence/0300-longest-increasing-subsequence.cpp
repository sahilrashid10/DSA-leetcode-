//OPTIMAL APPROACH VIS: PATIENCE SORTING
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int> sorted;
        sorted.push_back(nums[0]);

        for(int i=1; i<n; i++){
            //just bigger element found replace that in sorted
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if(it != sorted.end()){
                *it = nums[i];
            } 
            else
                sorted.push_back(nums[i]);
        }
        return sorted.size();
    }
};
// BOTTOM UP
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);

//         int maxLen = 1;
//         for(int i=0; i<n; i++){
//             for(int j = 0; j<i; j++ ){
//                 if(nums[i] > nums[j]){
//                     dp[i] = max(dp[i], dp[j]+1);
//                     maxLen = max(maxLen, dp[i]);
//                 }
//             }
//         }
//         return maxLen;
//     }
// };
// MEMOIZATION
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