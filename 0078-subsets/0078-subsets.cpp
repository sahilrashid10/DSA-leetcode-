class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    int n;

    void solve(vector<int>& nums, int i){
        if(i == n){
            result.push_back(temp);
            return;
        } 

        temp.push_back(nums[i]);
        solve(nums, i+1);
        temp.pop_back();
        solve(nums, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        solve(nums, 0);
        return result;
    }
};