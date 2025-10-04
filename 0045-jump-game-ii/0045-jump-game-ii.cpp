class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        int s = 1, e = nums[0];
        int jumps = 1;
        
        while(e < n-1){
            int farthest = 0;
            
            for(int i=s; i<=e; i++)
                farthest = max(farthest, nums[i] + i);
            s = e + 1;
            e = farthest;
            jumps++;
        }
        return jumps;
    }
};

// time n^2, space n + n
// class Solution {
// public:
//     vector<int> dp;
//     int n;
//     int makeJumps(vector<int> &nums, int i){
//         if(i >= n-1) return 0;
//         if(dp[i] != -1) return dp[i];

//         int maxJump = nums[i] + i;
//         int ans = 1e9;
//         if(maxJump == i) return 1e9;

//         for(int k = i+1; k<=maxJump && k < n; k++){
//             ans = min(ans, 1 + makeJumps(nums, k));
//         }
//         return dp[i] = ans;
//     }
//     int jump(vector<int>& nums) {
//         n = nums.size();
//         if(n==1) return 0;
//         dp.assign(n, -1);
//         return makeJumps(nums, 0);
//     }
// };
// time n^n, space n stack space
// class Solution {
// public:
//     int n;
//     int makeJumps(vector<int> &nums, int i){
//         if(i >= n) return 0;

//         int jump = nums[i] + i;
//         int ans = 1001;
//         if(jump == i) return ans;

//         while(jump > 0){
//             ans = min(ans, 1 + makeJumps(nums, jump));
//             jump--;
//         }
//         return ans;
//     }
//     int jump(vector<int>& nums) {
//         n = nums.size();
//         return makeJumps(nums, 0);
//     }
// };