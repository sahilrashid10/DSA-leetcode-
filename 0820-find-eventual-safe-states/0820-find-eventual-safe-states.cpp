class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<vector<int>> adj(graph.size());
        vector<int> id(adj.size(), 0);

        for(int node=0; node<graph.size(); node++){
            for(auto &num : graph[node]){
                adj[num].push_back(node);
                id[node]++;
            }
        }
        set<int> safeNodes;
        queue<int>q;
        for(int i=0; i<id.size(); i++){
            if(id[i] == 0){
                q.push(i);
                safeNodes.insert(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int &nei : adj[node]){
                id[nei]--;
                if(id[nei] == 0){
                    q.push(nei);
                    safeNodes.insert(nei);
                }
            }
        }
        vector<int>ans(safeNodes.begin(), safeNodes.end());
        return ans;

    }
};