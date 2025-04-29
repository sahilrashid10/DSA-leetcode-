class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        
        vector<int> group(n);
        group[0] = 1;
        int gno = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] > maxDiff)
                group[i] = ++gno;
            else
            group[i] = gno; 
        }
        
        vector<bool> result;
        for(auto &it:q){
            if(group[it[0]] == group[it[1]] )
                result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};
