class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        using NODE = pair<int, vector<int>>;
        int r = moveTime.size(),
            c = moveTime[0].size();

        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        priority_queue<NODE, vector<NODE>, greater<NODE>> q;

        q.push({0, {0, 0, 1}});
        dist[0][0] = 0;

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            auto[time, node] = q.top();
            q.pop();
            
            if(node[0] == r-1 && node[1] == c-1)
                return dist[r-1][c-1];
            
            if(dist[node[0]][node[1]] < time)
                continue;
            
            for(auto &[dx, dy]:dir){
                int x = node[0] + dx, 
                    y = node[1] + dy;
                
                if(x >=0 && y >= 0 && x < r && y < c){
                    int wait = 0;
                    if (time < moveTime[x][y])
                        wait = moveTime[x][y] - time;

                    int newTime = time + wait + node[2];
                    int t = node[2] == 1 ? 2 : 1;
                    if(newTime < dist[x][y]){
                        q.push({newTime, {x, y, t}});
                        dist[x][y] = newTime;
                    }
                }
            }
        }
        return 0;
    }
};