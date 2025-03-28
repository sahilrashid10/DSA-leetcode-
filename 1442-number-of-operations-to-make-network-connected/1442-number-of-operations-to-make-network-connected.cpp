class Solution {
public:

    int find(vector<int> &par, int i){
        if(i == par[i])
            return i;
        return par[i] = find(par, par[i]);
    }

    void findUnion(vector<int> &par, vector<int> &rank,
        int i, int j, int &edges){

        int par_i = find(par, i);
        int par_j = find(par, j);

        if(par_i == par_j) return;

        if(rank[i] > rank[j])
            par[par_j] = par_i;
        else if(rank[i] < rank[j])
            par[par_i] = par_j;
        else{
            par[par_j] = par_i;
            rank[par_i]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size() < n-1) return -1;

        int edges = 0;
        vector<int> par(n);
        vector<int> rank(n, 0);

        for(int i=0; i<n; i++)
            par[i] = i;

        for(auto &it: c)
            findUnion(par, rank, it[0], it[1], edges);

        for(int i=0; i<n; i++){
            if(par[i] == i) edges++;
        }
        
        return edges-1;
    }
};