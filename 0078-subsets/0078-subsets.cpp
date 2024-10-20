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

// -------------------using recursion--------------------------------------------
class Solution{
public:
    void solve(vector<vector<int>>&p, vector<int>s, vector<int>&nums, int i, int n){
        //base case 
        if(i == n){
            p.push_back(s);
            return;
        }
        s.push_back(nums[i]);
        solve(p, s, nums, i+1, n);
        s.pop_back();
        solve(p,s, nums, i+1, n);
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>>power_set;
        int n = nums.size();
        vector<int>sub_set;
        solve(power_set, sub_set, nums, 0, n);
        return power_set;
    }
};
