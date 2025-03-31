class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int row = maze.size();
        int col = maze[0].size();
        
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()){

            int level = q.size();
            for(int i=0; i<level; i++){
                auto [r, c] = q.front();
                q.pop();

                for(auto &[dx, dy]:dir){
                    int x = r + dx, y = c + dy;

                    if(x<row && y<col && x>=0 && y>=0){
                        if(maze[x][y] == '.'){
                            maze[x][y] = '+';
                            q.push({x, y});
                        }
                    }else if(steps != 0) return steps;
                }
            }
            steps++;
        }
        return -1;
    }
};