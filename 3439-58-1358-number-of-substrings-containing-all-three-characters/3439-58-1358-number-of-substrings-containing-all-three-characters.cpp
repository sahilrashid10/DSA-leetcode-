//OPTIMAL APPROCAH-1 T=O(2N)~O(N), S=O(3)~O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count=0, l=0;
        vector<int>lastSeen = {-1,-1,-1};
        for(int r=0; r<n; r++){
            lastSeen[s[r]-'a'] = r;
            // if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
                int mini = min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
                count += 1+mini;
            // }
        }
        return count; 
    }
};
////OPTIMAL APPROCAH-1 T=O(2N)~O(N), S=O(3)~O(1)
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int totalComb = (1ll*n*(n+1))/2;
//         int lessEqual2=0, l=0;
//         unordered_map<char, int>m;
//         for(int r=0; r<n; r++){
//             m[s[r]]++;
//             while(m.size()>2){
//                 m[s[l]]--;
//                 if(m[s[l]]==0)
//                     m.erase(s[l]);
//                 l++;
//             }
//             lessEqual2 += r-l+1;
//         }
//     return totalComb-lessEqual2;
//     }
// };
//BRUTE FORCE: T=O(N^2), S=O(3);
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int count = 0;
//         for(int i=0; i<s.size(); i++){
//             unordered_map<char, int>m;
//             for(int j=i; j<s.size(); j++){
//                 m[s[j]]++;
//                 if(m.size() == 3){
//                     count += s.size()-j;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };