class Solution {
public:
    int ans=-1;
    void solve(vector<int>& nums, int k, int l, int r){
        if(l>r) return;
        int m = (l+r)/2;
        if(nums[m]==k){
            ans = m;
            return;
            }
        (nums[m]<k)?solve(nums, k,m+1 ,r):solve(nums, k, l,m-1);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        solve(nums, target, 0, n);
        return ans;
    }
};