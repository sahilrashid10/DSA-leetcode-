class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;

        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
            auto it = upper_bound(nums.rbegin(), nums.rbegin() + (n - i - 1), nums[i]);
            
            // Convert reverse_iterator to normal iterator
            int j = n - 1 - (it - nums.rbegin());
                swap(nums[i], nums[j]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }

        sort(nums.begin(), nums.end());
        return;

    }
};


//Solution 1:  Generate all and if size full then return sorted version
//else return next in the stored array, time and space (perm 1, 2) on leetcode