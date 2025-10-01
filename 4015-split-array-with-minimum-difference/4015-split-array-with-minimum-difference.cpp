class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> prefix(n);
        vector<long long> suffix(n);
        vector<bool> inc(n, false);
        vector<bool> dec(n, false);

        

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        inc[0] = true;
        dec[n-1] = true;

        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i])
                inc[i] = inc[i-1];
            prefix[i] = prefix[i-1]+nums[i];
        }
        
        for(int i=n-2; i>=0; i--){
            if(nums[i] > nums[i+1])
                dec[i] = dec[i+1];
            suffix[i] = suffix[i+1]+nums[i];
        }

        long long minDiff = LLONG_MAX;
        for(int i=0; i<n-1; i++){
            if(inc[i] == true && dec[i+1] == true)
                minDiff = min(minDiff, abs(prefix[i] - suffix[i+1]));
        }
        return minDiff == LLONG_MAX ? -1 : minDiff;
    }
};












