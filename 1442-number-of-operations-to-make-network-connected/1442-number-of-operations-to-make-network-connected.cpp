class Solution {
public:

    vector<int> p, rank;

    int find(int node){
        if(node == p[node]) return node;

        return p[node] = find(p[node]);
    }

    void unite(int node1, int node2){
        int node1_parent = find(node1);
        int node2_parent = find(node2);

        if(node2_parent == node1_parent) return;

        if(rank[node2_parent] < rank[node1_parent])
            p[node2_parent] = node1_parent;

        else if(rank[node2_parent] > rank[node1_parent])
            p[node1_parent] = node2_parent;
        else{
            p[node2_parent] =  node1_parent;
            rank[node1_parent] += 1;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        rank.resize(n, 0);
        p.resize(n);

        for(int i=0; i<n; i++)
            p[i] = i;

        int connectedNodes = 1, 
        cablesLeft = connections.size();

        for(auto &it:connections){
            int node1  = it[0],
            node2  = it[1];

            if(find(node1) != find(node2)){
                unite(node1, node2);
                connectedNodes++;
                cablesLeft--;
            }
        }

        int leftOutNodes = n - connectedNodes;
        return cablesLeft >= leftOutNodes ? leftOutNodes:-1;
    }
};