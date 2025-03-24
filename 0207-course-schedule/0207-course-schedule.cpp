class Solution {
public:
    bool isCycle(vector<vector<int>> &adj, vector<int> &visited, stack<int> &s, int i,
         vector<int> & pathVisited){
        visited[i] = 1;
        pathVisited[i] = 1;

        for(auto &node : adj[i]){
            if(!visited[node] && isCycle(adj, visited, s, node, pathVisited)){
                return true;
            }else if(pathVisited[node] == 1)
            return true;
        }
        pathVisited[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> adj(numCourses);
        for(auto &it : p){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        stack<int> s;
        for(int i=0; i<adj.size(); i++){
            if(!visited[i] && isCycle(adj, visited, s, i, pathVisited)){
                return false;
            }
        }
        return true;
    }
};