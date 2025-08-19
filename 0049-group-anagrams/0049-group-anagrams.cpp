class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        //n*klog(k)
        for(int i=0; i<strs.size(); i++){
            string sortedString = strs[i];

            sort(sortedString.begin(), sortedString.end());
            mp[sortedString].push_back(i);
        }
        //n
        vector<vector<string>> result;
        for(auto &[s, v]:mp){
            vector<string> temp;
            for(int i=0; i<v.size(); i++){
                temp.push_back(strs[v[i]]);
            }
            result.push_back(temp);
        }
        return result;
    }
};





// class Solution {
// public:
//     int n;

//     bool isAnagram(string &s, string &t){
//         if(s.size() != t.size()) return 0;

//         vector<int> freq(26 , 0);
//         for(int i=0; i<s.size(); i++){
//             freq[s[i]-'a']++;
//             freq[t[i]-'a']--;
//         }
//         for(int i=0; i<26; i++){
//             if(freq[i] != 0) return 0;
//         }

//         return 1;
        
//     }
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         n = strs.size();
//         vector<int> visited(n, 0);
//         vector<vector<string>> result;

//         for(int i=0; i<n; i++){
//             if(visited[i]) continue;

//             visited[i] = 1;
//             vector<string> temp;
//             temp.push_back(strs[i]);

//             for(int j = i+1; j<n; j++){
//                 if(isAnagram(strs[i], strs[j])){
//                     temp.push_back(strs[j]);
//                     visited[j] = 1;
//                 }
//             }
//             result.push_back(temp);
//         }
//         return result;
//     }
// };