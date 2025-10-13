class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<m; i++)
            mp[t[i]].push_back(i);
        
        long long p = -1;
        for(int i=0; i<n; i++){
            if(mp.count(s[i]) == 0)
                return false;
            vector<int> &v = mp[s[i]];

            auto it = upper_bound(v.begin(), v.end(), p);
            if(it == mp[s[i]].end()) return false;
            p = *it;
        }
        
        return true;
    }
};
// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int n = s.size();
//         int m = t.size();

//         int k = 0;
//         int i=0;
//         while(k < m){
//             if(s[i] == t[k]) i++;
//             k++;
//         }
//         return i == n;
//     }
// };