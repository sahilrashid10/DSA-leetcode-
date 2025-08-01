class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<vector<pair<int, int>>> adj(v);

        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(i == j) continue;
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, cost});
                adj[j].push_back({i, cost});
            }
        }
        vector<int> visited(v, 0);
        using NODE = pair<int, int>;
        priority_queue<NODE, vector<NODE>, greater<NODE>> q;
        q.push({0, 0});

        int sum = 0;
        while(!q.empty()){
            auto[cost, node] =  q.top();
            q.pop();

            if(visited[node]) continue;

            sum += cost;
            visited[node] = 1;
            for(auto &it:adj[node]){
                int adjNode = it.first; 
                int curCost = it.second; 
                if(!visited[adjNode]){
                    q.push({curCost, adjNode});
                }
            }
        }  
        return sum;  
    }
};