class Solution {
public:
    int row, col;
    vector<pair<int, int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, 
    int r, int c){
        visited[r][c] = 1;
        for(auto &[x, y]:dir){
            int newX = r + x;
            int newY = c + y;
            if(newX < row && newX >=0 && newY < col && newY >=0){
                if(!visited[newX][newY] && grid[newX][newY] == '1'){
                    dfs(grid, visited, newX, newY);
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));

        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};