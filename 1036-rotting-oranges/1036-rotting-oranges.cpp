class Solution {
public:
    //Right, Left, Up, Down
    vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), columns = grid[0].size();

        int fresh_oranges = 0, Affected_oranges = 0;
        vector<vector<int>> visited(rows, vector<int>(columns, 0));

        int time = 0;
        // NODE = {row, col}
        using NODE =  pair<int, int>;
        queue<NODE>q;
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visited[i][j] = 1;
                }
                else if(grid[i][j] == 1)
                    fresh_oranges++;
            }
        }

        // Start the timer
        while(!q.empty()){
            if(Affected_oranges == fresh_oranges) return time;

            int size = q.size();
            for(int i=0; i<size; i++){

                auto [row, col] = q.front();
                q.pop();

                for(auto &[dx, dy]:dir){
                    int x = row + dx;
                    int y = col + dy;

                    if(x < rows && y < columns && x >= 0 && y>=0){
                        if(!visited[x][y] && grid[x][y] == 1){
                            Affected_oranges++;
                            visited[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }

            }
            time++;
        }

        if(Affected_oranges != fresh_oranges) return -1;

        return time;

    }
};