class Solution {
public:
    int n;
    vector<int> dp;
    int solve(vector<int> &nums, int i){
        if(i < 2)  return 0;

        if(dp[i] != -1) return dp[i];
        int take = 0;
        if(nums[i-1] - nums[i-2] == nums[i] - nums[i-1])   
            take = 1 + solve(nums, i-1);
        else    
            int skip = solve(nums, i-1);
        
        return dp[i] = take;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        n = nums.size();
        if(n < 3)   return 0;

        dp.resize(n, -1);
        int result = 0;
        for(int i=2; i<n; i++){
            result  += solve(nums, i);
        }
        return result;
    }
};
// class Solution {
// public:
//     int n;
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         n = nums.size();
//         if(n < 3)   return 0;

//         int count = 0;
//         for(int i=1; i<n-1; i++){ 
//             int diff = nums[i] - nums[i-1];
//             int prev = nums[i];
//             for(int j = i+1; j<n; j++){
//                 if(nums[j] - prev != diff)  break;
//                 prev = nums[j];
//                 count++;
//             }
//         }
//         return count;
//     }
// };