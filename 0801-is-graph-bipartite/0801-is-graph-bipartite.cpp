class Solution {
public:

    bool dfs(vector<vector<int>>& graph,vector<int> &visited, int i, int cur){
        visited[i] = cur;

        for(auto &node : graph[i]){
            if(visited[node] == -1 && !dfs(graph, visited, node, !cur)){
                return false;
            }else if(cur == visited[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(visited[i] == -1 && !dfs(graph, visited, i, 0))
                return false;
        }
        return true;
    }

};