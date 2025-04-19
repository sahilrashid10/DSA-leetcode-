class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return 0;
        int ans = 0;
        unordered_map<long long, int> dp[n];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {

                long long dif = (long long)nums[i] - nums[j];
                int cnt = dp[j][dif];

                ans += cnt;
                dp[i][dif] += cnt + 1;
            }
        }
        return ans;
    }
};

//DOUBT: // IN TEST CASE [7, 7, 7, 7, 7] 0, 1, 4 NOT TAKEN
// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size();
//         if(n < 3)   return 0;

//         int ans = 0;
//         for(int i=0; i<n-2; i++){
//             for(int j = i+1; j<n; j++){
//                 int dif = nums[j] - nums[i];
//                 int count = 0;
//                 for(int k = j+1; k<n; k++){
//                     if(nums[k] - nums[k-1] != dif){
//                         count = 0;
//                         continue;
//                     }
//                     count++;
//                     ans +=  count;
//                 }
//             }
//         }
//         return ans;
//     }
// };