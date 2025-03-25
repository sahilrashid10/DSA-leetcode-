class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, l = 0, maxFreq = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < s.size(); r++) {
            maxFreq = max(maxFreq, ++freq[s[r] - 'A']);

            if ((r - l + 1) - maxFreq > k)
                freq[s[l++] - 'A']--;

            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int maxLen = 0;
//         for (int i = 0; i < s.size(); i++) {

//             vector<int> freq(26, 0);
//             string sub = "";
//             int maxFreq = 0;

//             for(int j = i; j < s.size(); j++){
//                 char ch = s[j];
//                 sub.push_back(ch);
//                 freq[ch - 'A']++;
//                 maxFreq = max(maxFreq, freq[ch-'A']);

//                 int changes = sub.size() - maxFreq;

//                 if(changes <= k){
//                     maxLen = max(maxLen, j - i + 1);
//                 }else break;
//             }
//         }
//         return maxLen;
//     }
// };