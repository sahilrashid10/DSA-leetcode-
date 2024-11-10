class Solution {
public:
    int ans;
    void modiFiedBinarySearch(vector<int>& nums, int s, int e){
        if(nums[s]!=nums[s+1]){
            ans = nums[s];
            return;
        }
        if(nums[e]!=nums[e-1]){
            ans = nums[e];
            return;
        }
        s=s+1;
        e=e-1;
        while(s<=e){
            int m = (s+e)/2;
            if(nums[m-1]!=nums[m] && nums[m]!=nums[m+1]){
                ans = nums[m];
                return;
                }
            if(m%2 == 0){
                if(nums[m]==nums[m-1])
                    e = m-1;
                else
                    s = m+1;
            }
            else{
                if(nums[m]==nums[m+1])
                    e = m-1;
                else
                    s = m+1;
            }
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        modiFiedBinarySearch(nums, 0, nums.size()-1);
        return ans;
    }
};