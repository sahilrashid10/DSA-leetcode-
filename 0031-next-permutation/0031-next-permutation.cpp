class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;
        while(i >=0 ){
            while(i >=0 && nums[i] >= nums[i+1])
                i--;
            if( i >= 0){
                int j= n-1;
                while(nums[j] <= nums[i])
                    j--;
                swap(nums[i], nums[j]);
                break;
            }
        }
        if(i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};



// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(), nums.end());
//     }
// };