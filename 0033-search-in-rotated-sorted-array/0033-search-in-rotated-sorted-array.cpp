class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        while(s<=e){
            int m = (s+e)/2;

            if(nums[m] == target) return m;

            if(nums[s] <= nums[m]){

                if(nums[s] <= target && target < nums[m])
                    e = m - 1;
                else{
                    s = m + 1;
                }

            }else{
                if(nums[m] < target && target <= nums[e])
                    s = m + 1;
                else 
                    e = m - 1;
            }
        }
        return -1;
    }
};