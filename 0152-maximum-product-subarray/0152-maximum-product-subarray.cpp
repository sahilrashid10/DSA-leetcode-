class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p=1, s=1, n = nums.size(), maxProduct = INT_MIN;
        for(int i=0; i<n; i++){
            if(s==0) s = 1;
            if(p==0) p = 1;

            p = p*nums[i];
            s = s*nums[n-i-1];

            maxProduct = max(maxProduct, max(p, s));
        }
        return maxProduct;
    }
};