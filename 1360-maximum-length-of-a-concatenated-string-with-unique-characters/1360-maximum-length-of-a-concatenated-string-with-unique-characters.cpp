class Solution {
public:
    int n;
    unordered_map<string, int> dp;

    // Checks if s1 and s2 can be concatenated without repeating characters
    bool canTake(const string& s1, const string& s2) {
        vector<int> freq(26, 0);
        for (char c : s1) freq[c - 'a']++;
        for (char c : s2) freq[c - 'a']++;

        for (int count : freq)
            if (count > 1) return false;

        return true;
    }

    int solve(vector<string>& arr, int i, const string& temp) {
        if (i == n) return temp.size();
        if (dp.count(temp)) return dp[temp];

        int take = 0, skip = 0;

        if (canTake(arr[i], temp))
            take = solve(arr, i + 1, temp + arr[i]);
        
        skip = solve(arr, i + 1, temp);

        return dp[temp] = max(take, skip);
    }

    int maxLength(vector<string>& arr) {
        n = arr.size();
        return solve(arr, 0, "");
    }
};
