class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    int N;

    bool canPlace(int row, int col){
        int r = row;
        int c = col;

        while(r >=0 && c>=0){
            if(board[r--][c--] == 'Q') 
                return false;
        }
        r = row;
        c = col;

        while(c>=0){
            if(board[r][c--] == 'Q') 
                return false;
        }
        c = col;
        while(r < N && c>=0){
            if(board[r++][c--] == 'Q') 
                return false;
        }

        return true;

    }
    void placeQueens(int col){
        if(col == N){
            ans.push_back(board);
            return;
        } 

        for(int row = 0; row < N; row++){
            if(canPlace(row, col)){
                board[row][col] = 'Q';
                placeQueens(col+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string(n, '.'));
        N = n;
        placeQueens(0);
        return ans;                                       
    }
};                   