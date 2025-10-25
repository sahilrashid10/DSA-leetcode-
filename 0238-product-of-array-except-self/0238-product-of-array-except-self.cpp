class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> suf(n);

        suf[n-1] = 1;
        for(int i=n-2; i >= 0; i--){
            suf[i] = nums[i + 1] * suf[i + 1];
        }
        int pre = 1;
        for(int i=0; i<n; i++){
            ans.push_back(pre * suf[i]);
            pre *= nums[i];
        }

        return ans;

    }
};