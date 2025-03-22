class Solution {
public:
    set<vector<int>> s;
    void twoSum(vector<int>& nums, int k, int i, int j, vector<vector<int>> &result){
        int target = -nums[k];

        while(i < j){
            int sum = nums[j] + nums[i];
            if(sum < target) i++;
            else if(sum > target) j--;
            else{
                result.push_back({nums[k], nums[i], nums[j]});
                i++;
                j--;
                while(i<j && nums[i] == nums[i-1]) i++;
                while(i<j && nums[j] == nums[j+1]) j--;
            } 
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for(int k=0; k<n-2; k++){
            if(k>0 && nums[k] == nums[k-1])
                continue;
            twoSum(nums, k, k+1, n-1, result);
        }
        return result;
    }
};