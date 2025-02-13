class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];  
    }
    
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp); 
        vector<vector<int>> ans = {v[0]};
        for (int i = 1; i < v.size(); i++) {

            int s = v[i][0];
            int e = v[i][1];

            if (!ans.empty() && e <= ans.back()[1]) 
                continue;
            else{
                if (ans.back()[1] >= v[i][0]) { 
                    ans.back()[1] = max(ans.back()[1], v[i][1]);  
                }else 
                    ans.push_back({v[i][0], v[i][1]});
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     static bool cmp(vector<int>& a, vector<int>& b) {
//         return a[0] < b[0];  
//     }
    
//     vector<vector<int>> merge(vector<vector<int>>& v) {
//         sort(v.begin(), v.end(), cmp); 
//         int idx = 0;

//         for (int i = 1; i < v.size(); i++) {
//             if(v[idx][1] >= v[i][0]){
//                 v[idx][1] = max(v[idx][1], v[i][1]);
//             }else
//                 v[++idx] = v[i];
//         }
//         v.resize(idx+1); 

//         return v;
//     }
// };
