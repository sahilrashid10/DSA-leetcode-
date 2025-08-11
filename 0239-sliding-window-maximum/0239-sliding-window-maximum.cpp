class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q; // store indices, not values
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of current window
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            
            // Remove indices whose values are smaller than current nums[i]
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            
            // Add current index
            q.push_back(i);
            
            // Once first window is complete, record max
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        
        return ans;
    }
};
