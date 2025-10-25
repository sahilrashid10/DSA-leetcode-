class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = *max_element(nums.begin(), nums.end());

        int curSum = 0;
        for(int i=0; i<nums.size(); i++){
            curSum += nums[i];
            if(curSum < 0) curSum = 0;
            else maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};