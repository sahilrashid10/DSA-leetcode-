class Solution {
public:

    bool bfs(vector<vector<int>> &adj, vector<int> &color, int i){
        queue<int> q;
        q.push(i);
        color[i] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
    
            for (int neighbor : adj[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = !color[node];
                    q.push(neighbor);
                }else if(color[neighbor] == color[node]) return true;
            }
        }
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        vector<int> color(n+1, -1);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1; i<=n; i++){
            if(color[i] == -1 && bfs(adj, color, i))
                return false;
        }
        return true;
    }

};