class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        unordered_map<char, int>m;
        int maxLen = 0;
        if(s.size() == 0) return maxLen;
        int i = 0;
        for(int j=0; j<s.size(); j++){
            char c = s[j];
            m[c]++;
            while(m[c] > 1){
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(m[s[i]]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};