class Solution {
public:
    int mini=INT_MAX;
    void modifiedBinarySearch(vector<int>& nums, int s, int e){
        while(s<=e){
            int m = (s+e)/2;
            //check if left part is sorted
            if(nums[m]>=nums[s]){
                mini = min(mini, nums[s]);
                s = m+1;
            }
            // by default when left isn't sorted right will be
            else{
                mini = min(mini, nums[m]);
                e = m-1;
            }
        }
    }
    int findMin(vector<int>& nums) {
        modifiedBinarySearch(nums, 0, nums.size()-1);
        return mini;
    }
};