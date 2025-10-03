class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(val == nums[i]){
                count++;
                nums[i] = 50;
            }
        }
        sort(nums.begin(), nums.end());
        return n - count;
    }
};