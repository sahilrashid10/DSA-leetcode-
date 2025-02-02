class Solution {
public:

void twoSum(vector<int>& nums, int i, vector<vector<int>>& result) {
    int a = nums[i];
    int l = i + 1;
    int r = nums.size() - 1;
    
    while (l < r) {
        int sum = nums[l] + nums[r];
        
        if (sum < -a) {
            l++;  
        } else if (sum > -a) {
            r--;   
        } else {
            // Found a valid triplet
            result.push_back({a, nums[l], nums[r]});
            l++; 
            r--; 
            
    
            while (l < r && nums[l] == nums[l - 1]) l++; 
            while (l < r && nums[r] == nums[r + 1]) r--; 
        }
    }
}

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the array
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            twoSum(nums, i, result);
        }
        return result;
    }
};
