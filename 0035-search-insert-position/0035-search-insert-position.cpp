class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l,r,m;
        l=0;
        r=nums.size()-1;
        while(l<=r){
            m = (r+l)/2;
            if(nums[m]==target) return m;
            (nums[m]<target)?(l=m+1):(r=m-1);
        }
        return l;
    }
};