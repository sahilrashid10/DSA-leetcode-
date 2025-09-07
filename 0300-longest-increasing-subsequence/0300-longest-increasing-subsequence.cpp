// nlogn time and n space
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sorted;
        for(int &num:nums){
            if(sorted.size() == 0){
                sorted.push_back(num);
                continue;
            }
            auto it  = lower_bound(sorted.begin(), sorted.end(), num);
            if(it != sorted.end())
                *it = num;
            else
                sorted.push_back(num);
        }
        return sorted.size();
    }
};
// time O(n^2) space O(n)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         int maxLen = 1;
//         vector<int> t(n, 1);
//         for(int i=0; i<n; i++){
//             int j = 0;
//             while(j < i){
//                 if(nums[j] < nums[i])
//                     t[i] = max(t[j] + 1, t[i]);
//                 maxLen = max(maxLen, t[i]);
//                 j++;
//             }
//         }
//         return maxLen;
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