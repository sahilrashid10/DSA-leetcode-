class Solution {
public:
    int n, m;
    vector<pair<int, int>>dirn = {{0,1},{0,-1},{1,0},{-1,0}};
    bool solve(vector<vector<char>>&board, string &word, int idx, int i, int j){
        if(idx == word.size()) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[idx] || board[i][j]=='$')
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';
        for(auto it:dirn){
            int new_i = i + it.first;
            int new_j = j + it.second;
            if(solve(board, word, idx+1, new_i, new_j)){
                return true;
                }
        }
        board[i][j] = temp;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word){
        n= board.size();
        m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0] && solve(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
/*Time Complexity: 
O(m×n×4^L)
Space Complexity: 
O(L)*/