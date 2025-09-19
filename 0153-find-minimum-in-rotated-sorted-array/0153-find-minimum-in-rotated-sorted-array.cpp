class Solution {
public:
    int findMin(vector<int>& nums) {
        int minValue = INT_MAX;
        int n = nums.size();
        int s = 0, e = n-1;

        while(s <= e){
            int m = s + (m-s)/2;

            if(nums[s] <= nums[m]){
                minValue = min(minValue, nums[s]);
                s = m+1;
            }else{
                minValue = min(minValue, nums[m]);
                e = m - 1;
            }
        }
        return minValue;
    }
};