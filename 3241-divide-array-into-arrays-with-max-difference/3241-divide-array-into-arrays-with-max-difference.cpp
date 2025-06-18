class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());

        vector<int> temp;
        for(int i=0; i<n; i++){
            temp.push_back(nums[i]);

            if(temp.size() == 3){
                if(*temp.rbegin() - *temp.begin() > k)
                    return {};
                result.push_back(temp);
                temp = {};
            }
        }
        return result;
    }
};