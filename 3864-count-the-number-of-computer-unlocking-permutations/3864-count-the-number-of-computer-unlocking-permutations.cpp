class Solution {
public:
    int countPermutations(vector<int>& nums) {
        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i] <= nums[0])
                return 0;
        }
        long long ans = 1;
        int m = 1e9+7;
        for(int i = n-1; i > 0; i--){
            ans = (ans * i)%m;
        }
        return int(ans);
    }
};