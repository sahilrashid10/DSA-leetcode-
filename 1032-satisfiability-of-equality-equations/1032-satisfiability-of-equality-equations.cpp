class Solution {
public:
    vector<int> p, rank;

    int find(int i){
        if(i == p[i]) return i;

        return p[i] = find(p[i]);
    }

    void unite(int x, int y){
        int xp = find(x);
        int yp = find(y);

        if(xp == yp) return;

        if(rank[xp] < rank[yp])
            p[xp] = yp;
        else if(rank[xp] > rank[yp])
            p[yp] = xp;
        else{
            p[xp] = yp;
            rank[yp] += 1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        p.resize(26);
        rank.resize(26, 0);

        for(int i=0; i<26; i++)
            p[i] = i;

        for(string &s:equations){
            if(s[1] == '=')
                unite(s[0] - 'a', s[3] - 'a');
        }
        for(string &s:equations){
            if(s[1] == '!'){
                if(find(s[0]-'a') == find(s[3] - 'a'))
                    return false;
            }
        }
        return true;
    }
};