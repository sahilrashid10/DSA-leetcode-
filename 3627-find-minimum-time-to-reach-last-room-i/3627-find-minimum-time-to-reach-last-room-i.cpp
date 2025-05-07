class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        using NODE = pair<int, pair<int, int>>;
        int r = moveTime.size(), c = moveTime[0].size();
        // min heap
        priority_queue<NODE, vector<NODE>, greater<NODE>> pq;

        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            int x0 = node.first, y0 = node.second;

            if (time > dist[x0][y0]) continue;

            for(auto &[dx, dy] : dir){
                int x = dx + node.first;
                int y = dy + node.second;
                if(x >=0 && y >= 0 && x < r && y < c){
                    int newTime = time + 1;
                    if(time < moveTime[x][y])
                        newTime += moveTime[x][y] - time;

                    if(dist[x][y] > newTime){
                        dist[x][y] = newTime;
                        pq.push({newTime, {x, y}});
                    }
                }
            }
        }
        return dist[r-1][c-1];
    }
};