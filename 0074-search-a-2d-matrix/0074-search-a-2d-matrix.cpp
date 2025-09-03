class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int rows = m.size();
        int cols = m[0].size();

        int s = 0;
        int e = cols-1;

        for(int i=0; i<rows; i++){
            if(m[i][s] <= t && t <= m[i][e]){
                int j = 0;
                while(j < cols){
                    if(t == m[i][j])
                        return true;
                    j++;
                }
                return false;
            }
        }
        return false;
    }
};