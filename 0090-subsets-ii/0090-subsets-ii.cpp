class Solution {
public:

    void helper(vector<int> &nums, vector<vector<int>> &result, vector<int> temp, int i){
        result.push_back(temp);
        for(int j=i; j<nums.size(); j++){
            if(j != i && nums[j-1] == nums[j]) continue;

            temp.push_back(nums[j]);

            helper(nums, result, temp, j+1);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;

        helper(nums, result, temp, 0);
        return result;   
    }
};