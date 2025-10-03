class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        for(int i=0; i<n; i++){
            if(k < n-1 && nums[k] != nums[i]){
                k++;
                nums[k] = nums[i];
            }
        }
        return k+1;
    }
};