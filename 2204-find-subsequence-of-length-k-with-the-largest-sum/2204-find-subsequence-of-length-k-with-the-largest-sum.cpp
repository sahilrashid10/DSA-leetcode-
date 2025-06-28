class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        using NODE = pair<int, int>;
        priority_queue<NODE> max_heap;
        for(int i=0; i<nums.size(); i++){
            max_heap.push({nums[i], i});
        }

        vector<int> ans;
        while(!max_heap.empty() && ans.size() < k){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++){
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
};