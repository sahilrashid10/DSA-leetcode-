class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int j=0; j<=n-3; j++){
            int sum = nums[j]+nums[j+2], num=nums[j+1];

            if(sum == num/2.0) count++;
        }
        return count;
    }
};

//crux int 1 ==  1.0