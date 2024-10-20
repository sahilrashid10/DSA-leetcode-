class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>>power_set;
        int n = nums.size();
        for(int i=0; i<(1<<n); i++){     // (1<<n)==2^n - left shift
        vector<int>sub_set;
            for(int j=0; j<n; j++){
                if(i & (1<<j))
                    sub_set.push_back(nums[j]);
            }
            power_set.push_back(sub_set);
        }
        return power_set;
    }
};