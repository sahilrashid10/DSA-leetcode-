class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;
        unordered_set<char> st;
        int i=0;
        int maxLen = 1;
        st.insert(s[i]);
        for(int j = 1; j<n; j++){

            if(st.count(s[j]) > 0){
                while(s[i] != s[j]){
                    st.erase(s[i]);
                    i++;
                }
                i++;
            }
            st.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};