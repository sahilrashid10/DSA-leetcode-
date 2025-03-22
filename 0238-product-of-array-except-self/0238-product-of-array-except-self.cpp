class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());   // suffix-product
        ans[nums.size() - 1] = 1;
        for(int i=nums.size()-2; i>=0; i--){
            ans[i] = ans[i+1]*nums[i+1];
        }
        int p=1;
        for(int i=0; i<nums.size(); i++){
            ans[i] = p*ans[i];
            p *= nums[i]; 
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int p = 1, z=0;
//         vector<int> ans(nums.size(), 0);
//         for(int &i : nums){
//             if(i == 0 && z < 2) z++;
//             else
//                 p *= i;
//             if(z == 2)
//                 return ans;
//         }
//         for(int i = 0; i<nums.size(); i++){
//             if(nums[i] == 0) ans[i] = p;
//             if(z == 0) ans[i] = p/nums[i];
//         }
//         return ans;
//     }
// };