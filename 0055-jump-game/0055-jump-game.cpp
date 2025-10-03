class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int maxJump = 0;
        for(int i=0; i<n-1; i++){
            maxJump = max(maxJump, nums[i] + i);

            if(nums[i] == 0 && maxJump <= i) return false;

        }
        
        return true;
        
    }
};