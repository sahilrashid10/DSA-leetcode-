class Solution {
public:
    int n;

    void getPs(vector<int>& nums, vector<int>& v) {
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] > nums[i])
                s.pop();
            v[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
    }

    void getNs(vector<int>& nums, vector<int>& v) {
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] > nums[i])
                s.pop();
            v[i] = s.empty() ? n : s.top();
            s.push(i);
        }
    }

    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        vector<int> ps(n), ns(n);

        getPs(nums, ps);
        getNs(nums, ns);

        int maxLen = 0, z = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) continue;
            z++;
            int len = ns[i] - ps[i] - 2;
            maxLen = max(maxLen, len);
        }
        if (z == 0) return n - 1; 
        return maxLen;
    }
};
