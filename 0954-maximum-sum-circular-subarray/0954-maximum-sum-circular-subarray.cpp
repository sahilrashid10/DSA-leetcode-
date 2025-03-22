class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX;
        int curMin = 0, curMax = 0;
        int sumNum = 0;

        for(int &num : nums){
            sumNum += num;

            curMax = max(num, curMax + num);
            curMin = min(num, curMin + num);

            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);
        }
        return (maxSum > 0) ? max(maxSum, sumNum - minSum) : maxSum;

    }
};