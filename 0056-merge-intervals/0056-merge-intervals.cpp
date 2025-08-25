class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;

        sort(v.begin(), v.end());
        int i=0, j = 1;
        
        while(j<v.size()){

            if(v[i][1] >= v[j][0] && v[i][1] <= v[j][1])
                v[i][1] = v[j][1];    
            else if(v[j][1] <= v[i][1]){
                
            }
            else{
                ans.push_back(v[i]);
                i = j;
            }
            j++;
        }
        ans.push_back(v[i]);
        return ans;
    }
};