class Solution {
public:
    vector<vector<string>>ans;
    bool isSafe(vector<string>&board, int i, int j, int n){
        int r=j;
        int c=i;
        while(c>=0){
            if(board[r][c]=='Q')return false;
            c--;
        }
        r=j;
        c=i;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=j;
        c=i;
        while(r<n && c>=0){
            if(board[r][c]=='Q') return false;
            r++;
            c--;
        }
        return true;
    }
//* i column, j row
    void placeQueens(vector<string>&board,int i, int n){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j=0; j<n; j++){
            if(isSafe(board,i, j, n)){
                board[j][i] = 'Q';    
                placeQueens(board, i+1, n);
                board[j][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n){
    vector<string>board(n,string(n, '.'));
    placeQueens(board, 0, n);
    return ans;
    }
};