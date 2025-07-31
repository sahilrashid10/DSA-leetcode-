class Solution {
private: 
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& adj) {
        color[node] = col; 
        
        // Traverse adjacent nodes
        for(int it : adj[node]) {
            // If uncolored
            if(color[it] == -1) {
                if(!dfs(it, !col, color, adj)) return false; 
            }
            // If previously colored and have the same color
            else if(color[it] == col) {
                return false; 
            }
        }
        return true; 
    }

public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1); // Initialize color vector with -1
	    
        // Check for all connected components
        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                if(!dfs(i, 0, color, adj)) 
                    return false; 
            }
        }
        return true; 
    }
};