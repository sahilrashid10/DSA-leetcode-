// BRUTE FORCE : T=O(N^2), S=O(N)
// class Solution {
// public:
//     long long calculateScore(string s){
//         long long score = 0;
//         long long n = s.size();
//         vector<long long>visited(n,0);
    
//         for(long long i=0; i<n; i++){
//             bool flag = false;
//             long long temp = 0;
//             for(long long j=0; j<i; j++){
//                 if(visited[j] != -1){
//                     if((s[i]+s[j])== 219){
//                         temp = max(temp,j);
//                         flag = true;
//                     }
//                 }
//             }
//             if(flag){
//                 score += i-temp;
//                 visited[i]=-1;
//                 visited[temp]=-1;
//             }
//         }
//         return score;
//     }
// };
class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        long long ans=0;
        unordered_map<int, vector<int>>mp;
        for(int i=0; i<n; i++){
            int cur = s[i]-'a', mir = 25 - cur;
            if(mp.find(mir)!= mp.end() && mp[mir].size()>0){
                ans += i - mp[mir].back();
                mp[mir].pop_back();
            }
            else
                mp[cur].push_back(i);
        }
        return ans;
    }
};