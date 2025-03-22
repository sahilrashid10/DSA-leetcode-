class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1, mini = INT_MAX;
        while(s<=e){
            int m = (s+e)/2;

            if(nums[s] <= nums[m]){
                mini = min(mini, nums[s]);
                s = m + 1;
            }else{
                mini = min(mini, nums[m]);
                e = m - 1;
            }
        }
        return mini;
    }
};