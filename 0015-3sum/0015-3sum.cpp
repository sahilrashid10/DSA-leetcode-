class Solution {
public:
    vector<vector<int>> result;
    int n;
    void check(vector<int>& nums, int k, int i, int j){
        int target = -1 * nums[k];

        while(i < j){

            int sum = nums[i] + nums[j];
            if(sum < target) i++;
            else if(sum > target) j--;
            else{
                vector<int> temp = {nums[k], nums[i], nums[j]};
                result.push_back(temp);
                i++;
                j--;

                while(i < j && nums[i] == nums[i-1]) i++;
                while(i < j && nums[j] == nums[j+1]) j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        for(int k = 0; k <= n-2; k++){
            if(k > 0 && nums[k] == nums[k-1]) continue;

            check(nums, k, k+1, n-1);
        }
        return result;
    }
};