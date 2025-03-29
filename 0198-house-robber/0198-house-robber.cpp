/*  BOTTOM UP */
class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        vector<int> t(nums.size() + 1);

        t[0] = 0, t[1] = nums[0];
        for(int i=2; i<t.size(); i++){
            int steal = nums[i-1] + t[i - 2];
            int skip = t[i-1];

            t[i] = max(steal, skip);
        }

        return t[t.size()-1];
    }
};

/*  TOP DOWN -RECURSION + MEMOIXATION */
// class Solution {
// public:
//     int dp[101];
//     int robThisShi(vector<int> &nums, int i){
//         if(i >= nums.size()) return 0;

//         if(dp[i] != -1)
//             return dp[i];

//         int robb = nums[i] + robThisShi(nums, i + 2);
//         int skip = robThisShi(nums, i + 1);


//         return dp[i] = max(skip, robb);
//     }
//     int rob(vector<int>& nums) {
//         memset(dp, -1, sizeof(dp));
//         int robbedMoney = robThisShi(nums, 0);

//         return robbedMoney;
//     }
// };

/*  RECURSION */
// class Solution {
// public:

//     int robThisShi(vector<int> &nums, int i){
//         if(i >= nums.size()) return 0;

//         int robb = nums[i] + robThisShi(nums, i + 2);
//         int skip = robThisShi(nums, i + 1);

//         return max(skip, robb);
//     }
//     int rob(vector<int>& nums) {

//         int robbedMoney = robThisShi(nums, 0);

//         return robbedMoney;
//     }
// };