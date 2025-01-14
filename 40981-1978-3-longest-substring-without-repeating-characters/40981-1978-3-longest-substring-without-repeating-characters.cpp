class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int max_len = 0, left = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (m.count(s[right])) 
                left = max(left, m[s[right]] + 1);
            m[s[right]] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

//BRUTE FORCE T=O(N^2), S=O(N) 
//Note: if erase() runs O(n) time the outer loop will exit bcz of flag making the code O(n^2) in all cases
// and if it runs n-2 times then it only runs once in inner loop so T = O(N*2N) = O(N^2)
//BASICALLY: it runs for only one iteration value of j and not all
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int max_len = (n==1)?1:0;
//         if(n<=1)
//             return max_len;
//         unordered_map<char, int>m;
//         int i;
//         int j;
//         bool flag = false;
//         for(i=0; i<n; i++){
//             for(j=i; j<n; j++){
//                 if(m.find(s[j])==m.end())
//                     m[s[j]] = j;
//                 else{
//                     max_len = max(j-i, max_len);
//                     m.clear();
//                     break;
//                 }
//                 if(j==n-1)
//                     flag = true;
//             }
//             if(flag)
//                 break;
//         }
//         if(!m.empty())
//             max_len = max(j-i, max_len);
//         return max_len; 
//     }
// };