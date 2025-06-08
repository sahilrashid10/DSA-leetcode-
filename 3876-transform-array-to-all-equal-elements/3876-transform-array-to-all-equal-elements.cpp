class Solution {
public:
    bool canDo(vector<int> nums, int k, int target) {
        int flips = 0;
        int n = nums.size();

        for(int i = 0; i < n-1; i++) {
            if(nums[i] != target) {
                nums[i] *= -1;
                nums[i+1] *= -1;
                flips++;
            }
        }

        if(nums[n-1] != target) return false;

        return flips <= k;
    }
    
    bool canMakeEqual(vector<int>& nums, int k) {

        return canDo(nums, k, 1) || canDo(nums, k, -1);
        
    }
};