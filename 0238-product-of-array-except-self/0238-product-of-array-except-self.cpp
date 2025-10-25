class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {0};

        vector<int> prefix(n, 0);
        prefix[0] = 1;
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        int suffix = 1;
        for(int i=n-1; i>=0; i--){
            prefix[i] = suffix * prefix[i];
            suffix *= nums[i];
        }
        return prefix;
    }
};
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return {0};

//         vector<int> ans(n, 0);
//         vector<int> prefix(n+1);
//         prefix[0] = 1;
//         for(int i=1; i<=n; i++){
//             prefix[i] = prefix[i-1] * nums[i-1];
//         }

//         int suffix = 1;
//         for(int i=n-1; i>=0; i--){
//             ans[i] = suffix * prefix[i];
//             suffix *= nums[i];
//         }
//         return ans;
//     }
// };