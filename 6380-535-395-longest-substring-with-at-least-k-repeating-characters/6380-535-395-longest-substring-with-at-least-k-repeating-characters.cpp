class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k > s.size())
            return 0;
        if (k == 1)
            return s.size();

        unordered_map<char, int> m;
        for (char &c : s)
            m[c]++;

        // Check if the entire string satisfies the condition
        for (auto &it : m) {
            if (it.second < k) {
                int start = 0, ans = 0;
                for (int i = 0; i < s.size(); i++) {
                    if (m[s[i]] < k) {
                        ans = max(ans, longestSubstring(s.substr(start, i - start), k));
                        start = i + 1;
                    }
                }
                // Handle the last substring
                ans = max(ans, longestSubstring(s.substr(start), k));
                return ans;
            }
        }

        return s.size(); // The entire string satisfies the condition
    }
};
