class Solution {
public:

    int m = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        using road = pair<long long, long long>; 
        vector<vector<pair<int ,int>>>adj(n);  
        for(auto &it : roads){
            adj[it[0]].push_back({it[2], it[1]}); // {dist, node}
            adj[it[1]].push_back({it[2], it[0]});
        }
        priority_queue<road, vector<road>, greater<road>> h; // min-heap
        vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n, 0);

        h.push({0, 0});
        time[0] = 0;
        ways[0] = 1;
        while(!h.empty()){    
            auto [curTime, curRoad] = h.top();  // t-O(1)
            h.pop();    // t - O(logV)

            if(curTime > time[curRoad])
                continue;

            for(auto[adjTime, adjRoad] : adj[curRoad]){  // t - O(E)
                long long newTime = curTime + adjTime;

                if(newTime < time[adjRoad]){
                    h.push({newTime, adjRoad});   // t- O(logV)
                    time[adjRoad] = newTime;
                    ways[adjRoad] = ways[curRoad];
                }else if(newTime == time[adjRoad])
                    ways[adjRoad] = (ways[adjRoad] + ways[curRoad])%m;

            }
        }
        return ways[n-1];
    }
};