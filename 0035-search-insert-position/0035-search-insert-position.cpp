class Solution {
public:
    int searchInsert(vector<int>& nums, int k) {
        int l=0;
        int r=nums.size()-1;
        int c=nums.size(); //c = ceil
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==k)
                return m;
            if(nums[m]>k){
                c = m;
                r = m-1;
                }
            else l = m+1;
            }
        return c;
    }
};