class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int r=0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                if(r < c) 
                    swap(matrix[r][c], matrix[c][r]);
            }
        }
        for(int i=0; i<rows; i++)
            reverse(matrix[i].begin(), matrix[i].end());
        
    }
};