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

            if(nums[n-i-1] == 0) 
                suffix = 1;
            if(nums[i] == 0) 
                preffix = 1;
        }

        return maxProduct;
    }
};

// Time: O(n), Space: O(n)
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n);

//         prefix[0] = nums[0];
//         int result = nums[0];

//         for (int i = 1; i < n; i++) {
//             prefix[i] = (prefix[i-1] == 0 ? 1 : prefix[i-1]) * nums[i];
//             result = max(result, prefix[i]);
//         }

//         int suffix = nums[n-1];
//         result = max(result, suffix);
//         for (int i = n-2; i >= 0; i--) {
//             suffix = (suffix == 0 ? 1 : suffix) * nums[i];
//             result = max(result, suffix);
//         }

//         return result;
//     }
// };


// Time: O(n), Space: O(2n)
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n), suffix(n);

//         prefix[0] = nums[0];
//         for (int i = 1; i < n; i++) {
//             prefix[i] = (prefix[i-1] == 0 ? 1 : prefix[i-1]) * nums[i];
//         }

//         suffix[n-1] = nums[n-1];
//         for (int i = n-2; i >= 0; i--) {
//             suffix[i] = (suffix[i+1] == 0 ? 1 : suffix[i+1]) * nums[i];
//         }

//         int result = nums[0];
//         for (int i = 0; i < n; i++) {
//             result = max({result, prefix[i], suffix[i]});
//         }

//         return result;
//     }
// };



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