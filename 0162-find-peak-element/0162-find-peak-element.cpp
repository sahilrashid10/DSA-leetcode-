class Solution {
public:
    int n;
    int ans;
    void modifiedBs(vector<int>& nums, int s, int e){
        if(n == 1) {ans = 0;return;}
        if(nums[0]>nums[1]) {ans = 0;return;}
        if(nums[n-1]>nums[n-2]){ans = n-1;return;}

        while(s<=e){
            int m = (s+e)/2;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                ans = m;
                return;
            }

            if(nums[m]>nums[m-1]) s = m+1;

            else if(nums[m]>nums[m+1]) e = m-1;
            //choice
            else s = m+1;
        }
    }
    int findPeakElement(vector<int>& nums) {
        n = nums.size();
        modifiedBs(nums, 1, n-2);
        return ans;
    }
};