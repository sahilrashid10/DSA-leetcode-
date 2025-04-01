class Solution {
public:
    vector<vector<int>> result;
    int n;
    void dfs(vector<vector<int>>& graph, vector<int> &temp, int node){
        
        //base case
        if(node == n-1){
            result.push_back(temp);
        }

        for(auto &adjNode:graph[node]){
            
            temp.push_back(adjNode);
            dfs(graph, temp, adjNode);
            temp.pop_back();
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        n = graph.size();
        vector<int> temp;
        temp.push_back(0);
        dfs(graph, temp, 0);
        return result;
    }
};