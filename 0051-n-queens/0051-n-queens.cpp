//APPROACH 1- T=(N!)   2- S=O(N)  recursion stack
// class Solution {
// public:
//     vector<vector<string>>ans;
//     bool isSafe(vector<string>&board, int i, int j, int n){
//         int r=j;
//         int c=i;
//         while(c>=0){
//             if(board[r][c]=='Q')return false;
//             c--;
//         }
//         r=j;
//         c=i;
//         while(r>=0 && c>=0){
//             if(board[r][c]=='Q') return false;
//             r--;
//             c--;
//         }
//         r=j;
//         c=i;
//         while(r<n && c>=0){
//             if(board[r][c]=='Q') return false;
//             r++;
//             c--;
//         }
//         return true;
//     }
// //* i column, j row
//     void placeQueens(vector<string>&board,int i, int n){
//         if(i==n){
//             ans.push_back(board);
//             return;
//         }
//         for(int j=0; j<n; j++){
//             if(isSafe(board,i, j, n)){
//                 board[j][i] = 'Q';    
//                 placeQueens(board, i+1, n);
//                 board[j][i] = '.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n){
//     vector<string>board(n,string(n, '.'));
//     placeQueens(board, 0, n);
//     return ans;
//     }
// };
/*OPTIMIZED SOLUTION
complexity remains same but the check fun time reduces from O(N) to O(1)
*/
class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<int, int> mp_row, mp_down_dia, mp_up_dia;

    void placeQueens(vector<string>& board, int i, int n) {
        if (i == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!mp_row[j] && !mp_down_dia[i + j] && !mp_up_dia[n - 1 + i - j]) {
                board[i][j] = 'Q';
                mp_row[j] = mp_down_dia[i + j] = mp_up_dia[n - 1 + i - j] = 1;
                placeQueens(board, i + 1, n);
                board[i][j] = '.';
                mp_row[j] = mp_down_dia[i + j] = mp_up_dia[n - 1 + i - j] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        placeQueens(board, 0, n);
        return ans;
    }
};
