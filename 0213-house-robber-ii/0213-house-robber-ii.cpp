class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> profit(n+1, 0);

        //case 1: including 0 idx
        for(int i=1; i<=n-1; i++){
            int skip = profit[i-1];
            int steal = nums[i-1] + ((i>=2)?profit[i-2]:0);
            
            profit[i] = max(skip, steal);
        }
        //save it here as later it will be modified
        int p1 = profit[n-1];
        //case 2: skipping 0 idx house
        profit[1] = 0;
        for(int i=2; i<=n; i++){
            int skip = profit[i-1];
            int steal =  nums[i-1] + profit[i-2];
            
            profit[i] = max(skip, steal);
        }
        return max(p1, profit[n]);
    }
};