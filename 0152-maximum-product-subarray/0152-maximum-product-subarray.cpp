class Solution {
public:
    int maxProduct(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();
        vector<ll> suf(n, 0);
        ll pre = 1;

        ll maxProduct = INT_MIN;
        ll product = 1;
        bool zeros = false;
        for(int i=n-1; i>=0; i--){
            if(nums[i] == 0){
                product = 1;
                zeros = true;
                continue;
            }
            product *= nums[i];
            suf[i] = product;
            maxProduct = max(maxProduct, product);
        }

        // product = 1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                pre = 1;
                continue;
            }
            pre *= nums[i];
            if(nums[i] < 0){
                maxProduct = max({pre, suf[i], maxProduct});
            }
            maxProduct = max(maxProduct, pre);
        }
        return maxProduct < 0 && zeros? 0 : maxProduct;

    }
};