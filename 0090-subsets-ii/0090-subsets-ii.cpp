class Solution {
public:
    vector<vector<int>>ans;
    vector<int>sub;
    void solve(vector<int> &nums, int i){
        
        ans.push_back(sub);
        for(int j=i; j<nums.size(); j++){
            if(j>i && nums[j]==nums[j-1])
                continue;
            sub.push_back(nums[j]);
            solve(nums, j+1);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
};