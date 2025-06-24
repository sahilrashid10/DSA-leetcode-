class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != key)
                continue;

            int start = max(0, i - k);
            int end = min(int(nums.size() - 1), i + k);
            if (!result.empty() && result.back() >= start)
                start = result.back() + 1;

            for (int j = start; j <= end; j++) {
                if(abs(j-i) <= k)
                    result.push_back(j);
            }
        }
        return result;
    }
};