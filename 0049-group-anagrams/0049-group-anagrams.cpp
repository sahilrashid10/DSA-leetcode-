class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;

        for(auto &s : strs){
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        for(auto &it : m)
            result.push_back(it.second);

        return result;
    }
};
// class Solution {
// public:
//     bool checkAngara(string &s1, string &s2, string &s) {
//         if(s1.size() != s2.size()) return false;

//         vector<int> f(26, 0);
//         for(int i=0; i<s1.size(); i++)
//             f[s1[i] - 'a']++;

//         for(int i=0; i<s2.size(); i++){
//             if(--f[s2[i] - 'a'] < 0 ) return false;
//         }
//         s = s2;
//         return true;
//     }
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> result;
//         unordered_map<string, int> m;

//         for(int i=0; i<strs.size(); i++){
//             if(m.find(strs[i]) != m.end())
//                 continue;

//             vector<string> temp = {strs[i]};
//             m[strs[i]]++;
//             for(int j = i+1; j<strs.size(); j++){
//                 string s;

//                 if(checkAngara(strs[i], strs[j], s)){
//                     m[strs[j]]++;
//                     temp.push_back(s);
//                 }
//             }
//             result.push_back(temp);
//         }
//         return result;
//     }
// };