class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=n-3; i>=0; i--){
            if(nums[i] + nums [i+1] > nums[i+2])
                return nums[i] + nums[i+1] + nums[i+2];
        }
        return 0;
    }
};


// class Solution {
// public:
//     int largestPerimeter(vector<int>& nums) {
//         int maxParameter = 0;
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<=nums.size()-3; i++){
//             for(int j = i+1; j<=nums.size()-2; j++){
//                 for(int k = j+1; k<=nums.size()-1; k++){
//                     if(nums[i] + nums[j] > nums[k]){
//                         maxParameter = max(maxParameter, nums[i]+nums[j]+nums[k]);
//                     }
//                 }
//             }
//         }
//         return maxParameter;
//     }
// };