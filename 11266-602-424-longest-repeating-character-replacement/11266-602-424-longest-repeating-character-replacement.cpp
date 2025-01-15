class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freqs(26, 0);
        int res = 0, i = 0, maxFreq = 0;

        for (int j = 0; j < s.size(); j++) {
            freqs[s[j] - 'A']++;
            maxFreq = max(maxFreq, freqs[s[j] - 'A']);

            if ((j - i + 1) - maxFreq > k) {
                freqs[s[i] - 'A']--;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};
