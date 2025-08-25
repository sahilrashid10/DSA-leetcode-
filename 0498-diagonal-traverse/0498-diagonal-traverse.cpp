class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size(),
        cols = mat[0].size();
        int i=0, j = 0;

        vector<int> ans;
        while(ans.size() < 1ll*rows * cols){
            while(i >= 0 && j < cols){
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(j >= cols){
                j--;
                i += 2;
            }
            else i++;

            while(j<cols && j >= 0 && i < rows){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            } 

            if(i >= rows){
                i--;
                j += 2;
            }
            else{
                j++;
            }

        }
        return ans;
    }
};