class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // using monotonic stack to find the greatest element on right
        int n = nums.size();

        int ans = -1;
        int maxi = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(maxi > nums[i]){
                ans = max(ans, maxi - nums[i]);
            }else
                maxi = nums[i];
        }
        return ans;

    }
};





// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) {
//         int n = nums.size();

//         int ans = -1;
//         for(int i=0; i<n-1; i++){
//             for(int j=i+1; j<n; j++){
//                 if(nums[j] > nums[i])
//                     ans = max(ans, nums[j] - nums[i]);
//             }
//         }
//         return ans;
//     }
// };