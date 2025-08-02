class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& preq) {
        vector<vector<int>> adj(V);
        vector<int> indg(V);
        for(auto it : preq){
            adj[it[1]].push_back(it[0]);
                indg[it[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0 ;i<V ; i++){
            if(indg[i]==0){ 
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
             for(auto it : adj[node]){
                indg[it]--;
                if(indg[it]==0){ 
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        if(ans.size()==V) return ans;
        return {};
    }
};