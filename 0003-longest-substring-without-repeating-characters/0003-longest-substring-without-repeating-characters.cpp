class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1) return 1;
        int maxLen = 0;
        vector<int> v(256, -1);
        int i = 0, j = 0;
        for(j=0; j<s.size(); j++){
            if(v[s[j]] != -1 && v[s[j]] >= i){
                i = v[s[j]] + 1;
            }
            maxLen = max(maxLen, j - i + 1);
            v[s[j]] = j;
        }
        return maxLen;
    }
};
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxLen = 0;
//         for(int i=0; i<s.size(); i++){
//             vector<int> v(256, 0);
//             string st = "";
//             for(int j=i; j<s.size(); j++){
//                 if(v[s[j]] == 1) break;
//                 st.push_back(s[j]);
//                 v[s[j]] = 1;
//             }
//             maxLen = max(maxLen, int(st.size()));
//         }
//         return maxLen;
//     }
// };