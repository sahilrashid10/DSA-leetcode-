class Solution {
public:
    int maxProduct(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();

        ll pre = 1;
        ll suf = 1;
        ll maxProduct = INT_MIN;
        for(int i=0; i<n; i++){

            pre *= nums[i];
            suf *= nums[n-i-1];

            maxProduct = max({pre, suf, maxProduct});

            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;

        }
        return maxProduct;

    }
};