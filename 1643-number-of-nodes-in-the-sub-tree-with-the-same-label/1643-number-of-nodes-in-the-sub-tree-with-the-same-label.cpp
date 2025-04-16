class Solution {
public:
    vector<int> ans;
    vector<int> visited;
    void dfs(vector<vector<int>> &adj, string &labels, vector<int> &labCount, int &after, int node){
        int before = labCount[labels[node]-'a'];
        labCount[labels[node]-'a']++;
        visited[node] = 1;
        for(int &adjNode : adj[node]){
            if(!visited[adjNode])
                dfs(adj, labels, labCount, after, adjNode);
        }
        after = labCount[labels[node]-'a'];
        ans[node] = after - before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> labCount(26, 0);
        visited.resize(n, 0);
        ans.resize(n);

        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int after = 0;
        dfs(adj, labels, labCount, after, 0);

        return ans;
    }
};