class Solution {
public:

    int find(vector<int> &par, int i){
        if(par[i] == i) return i;

        return par[i] = find(par, par[i]);
    }
    void findUnion(vector<int> &par, vector<int> &rank, int i, int j){
        int pi = find(par, i);
        int pj = find(par, j);

        if(pi == pj) return;

        if(rank[pi] < rank[pj]) par[pi] = pj;
        else if(rank[pi] > rank[pj]) par[pj] = pi;
        else{
            par[pj] = pi;
            rank[pi]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        vector<int> par(n);
        vector<int> rank(n);

        for(int i=0; i<n; i++){
            par[i] = i;
            rank[i] = 0;
        }
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    findUnion(par, rank, i, j);
            }
        }
        int nGroups = 0;
        for(int i=0; i<par.size(); i++){
            if(i == par[i])
                nGroups++;
        }
        return n - nGroups;
    }
};