class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;
    int n;
    unordered_map<int, int> m;

    void helper(vector<int>& nums ) {
        for (int i = 0; i < n; i++) {
            if (m[nums[i]] == 0) {
                m[nums[i]] = 1;
                subset.push_back(nums[i]);
                helper(nums);
                m[nums[i]] = 0;
                subset.pop_back();
            }
        }
        if(subset.size() == n)
        result.push_back(subset);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        helper(nums);
        return result;
    }
};