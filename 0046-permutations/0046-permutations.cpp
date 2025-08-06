class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;
    int n;
    vector<int> used; // using vector instead of unordered_map for O(1) access

    void helper(vector<int>& nums) {
        // Base case: if current subset size == n, we found a valid permutation
        if (subset.size() == n) {
            result.push_back(subset);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i] == 0) { // if element is not used
                used[i] = 1;
                subset.push_back(nums[i]);

                helper(nums);

                // backtrack
                used[i] = 0;
                subset.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        used.assign(n, 0); // initialize visited array
        helper(nums);
        return result;
    }
};
