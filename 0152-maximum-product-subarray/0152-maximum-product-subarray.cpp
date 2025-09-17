class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int suffix = 1;
        int preffix = 1;

        int maxProduct = INT_MIN;
        int countZero = 0;

        for(int i=0; i<n; i++){

            preffix = 1ll*preffix*nums[i];
            suffix = 1ll*suffix*nums[n-i-1];
            maxProduct = max({maxProduct, preffix, suffix, nums[i]});
            if(nums[i] == 0){ 
                preffix = 1;
                countZero = 1;
                continue;
            }
            if(nums[n-i-1] == 0){ 
                suffix = 1;
                countZero = 1;
                continue;
            }


        
        }

        return maxProduct < 0 && countZero == 1 ? 0 : maxProduct;
    }
};


// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int mp = INT_MIN;
//         for(int i=0; i<nums.size(); i++){
//             int p = 1;
//             for(int j = i; j<nums.size(); j++){
//                 p *= nums[j];
//                 mp = max(mp, p);
//             }
//         }
//         return mp;
//     }
// };