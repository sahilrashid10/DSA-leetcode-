class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e){
            int m = s + (e - s)/2;

            if(nums[m] == t) return true;

            if(nums[s] == nums[m] && nums[m] == nums[e]){
                s++;
                e--;
            }else if(nums[s] <= nums[m]){
                if(nums[s] <= t && t <= nums[m])
                    e = m - 1;
                else
                    s = m + 1;
            }else{
                if(nums[m] <= t && t <= nums[e])
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return false;      
    }
};