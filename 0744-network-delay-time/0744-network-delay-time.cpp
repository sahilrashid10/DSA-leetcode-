//imp- use n+1 as 1 indexed and skip 0 index , read below
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using node = pair<int, int>;
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it : times)
            adj[it[0]].push_back({it[2], it[1]});  //time - node

        priority_queue<node, vector<node>, greater<node>> h;   //min-heap
        vector<int> time(n+1, 1e9);

        h.push({0, k});  //time, node
        time[k] = 0;

        while(!h.empty()){
            auto [curTime, curNode] = h.top();
            h.pop();

            for(auto [adjTime, adjNode]: adj[curNode]){
                int newTime = adjTime + curTime;
                if(newTime < time[adjNode]){
                    h.push({newTime, adjNode});
                    time[adjNode] = newTime;
                }
            }
        }

        //skip 0 index
        int minTime = *max_element(time.begin()+1, time.end());

        return (minTime != 1e9) ? minTime : -1;
    }
};