class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> temp(nums.size(), 1);

        int i=0, j = nums.size()-1;
        for(int &num:nums){
            if(num == 0)
                temp[i++] = 0;
            if(num == 2)
                temp[j--] = 2;
        }
        nums = temp;
    }
};