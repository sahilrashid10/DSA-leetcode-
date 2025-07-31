class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> topoOrder;
        for(auto &it:prerequisites){
            int u = it[0], v = it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
                topoOrder.push_back(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int &adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                    topoOrder.push_back(adjNode);
                }
            }
        }
        return topoOrder.size() == numCourses;
    }
};