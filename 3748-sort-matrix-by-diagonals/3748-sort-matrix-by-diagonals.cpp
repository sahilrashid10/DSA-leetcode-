class Solution {
public:

    vector<vector<int>> result;
    int n;
    bool flag = 1;
    void sortDiagonal(int row, int col){
        vector<int> temp;
        int r=row, c=col;
        while(r<n && c < n){
            temp.push_back(result[r++][c++]);
        }
        sort(temp.begin(), temp.end());

        if(flag){
            int i = temp.size()-1;
            while(row<n)
                result[row++][col++] = temp[i--];
        }else{
            int i = 0;
            while(col<n)
                result[row++][col++] = temp[i++];
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        result = grid;
        n = grid.size();
    

        // Traverse the middle diagonal and bottom left diagonals
        for(int row=0; row<n; row++){
            sortDiagonal(row, 0);
        }

        // Traverse the top rightdiagonals
        flag = 0;
        for(int col=1; col<n; col++){
            sortDiagonal(0, col);
        }

        return result;
    }
};