class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(); 
        int maxXor = 0;
        int isNonZero = 0;

        for(int i=0; i<n; i++){
            maxXor = maxXor ^ nums[i];
            if(nums[i] != 0)
                isNonZero = 1;
        }
        if(!isNonZero) return 0;

        if(maxXor == 0) return n-1;
        return n;
    }
};