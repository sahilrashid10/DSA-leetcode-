class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> vis;

    void backtrack(vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // skip used elements
            if (vis[i]) continue;

            // skip duplicates: if nums[i] == nums[i-1] and previous one not used, skip
            if (i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;

            vis[i] = 1;
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // ensure duplicates are adjacent
        vis.assign(nums.size(), 0);
        backtrack(nums);
        return ans;
    }
};
