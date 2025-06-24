class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans;
        vector<int> idx;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == key)
                idx.push_back(i);
        }
        for(int i=0; i<nums.size(); i++){
            for(int j = 0; j<idx.size(); j++){
                if(abs(i - idx[j]) <= k){
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};