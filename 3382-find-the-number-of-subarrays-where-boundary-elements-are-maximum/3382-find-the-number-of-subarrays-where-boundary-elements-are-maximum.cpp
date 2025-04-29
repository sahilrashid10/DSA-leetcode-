class Solution {
public:
    int n;
    void getPrevGreater(vector<int>& nums, vector<int>& prevGreater) {
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                int top = s.top();
                s.pop();
                prevGreater[top] = i;
            }
            s.push(i);
        }
    }
    long long numberOfSubarrays(vector<int>& nums) {
        n = nums.size();
        vector<int> prevGreater(n, -1);
        getPrevGreater(nums, prevGreater);

        unordered_map<int, vector<int>> freq;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            auto &v = freq[nums[i]];
            v.push_back(i);
            int cutoff = prevGreater[i];
            auto it  = upper_bound(v.begin(), v.end(), cutoff); //binary search
            ans += (v.end() - it);
        }
        return ans;
    }
};