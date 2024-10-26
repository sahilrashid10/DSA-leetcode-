class Solution {
public:
int m;
int n;
    vector<vector<int>>directions = {{0,1}, {0,-1}, {1,0},{-1,0}};
    bool FindWord(vector<vector<char>>&board,string &word ,int i, int j, int len){
        if(len == word.length()) return true;

        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$')return false;

        if(word[len] != board[i][j]) return false;

        char ch = board[i][j];
        board[i][j] ='$';
        for(auto &dir: directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            if(FindWord(board, word, new_i, new_j, len+1))return true;
        }
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); 
        n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0] && FindWord(board,word ,i, j, 0))
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