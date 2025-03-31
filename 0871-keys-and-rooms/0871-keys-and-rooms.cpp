class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);

        vector<int>visited(rooms.size(), 0);
        visited[0] = 1;
        int visits = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(visits == rooms.size()) return true;

            for(auto &adjNode : rooms[node]){
                if(!visited[adjNode]){
                    q.push(adjNode);
                    visited[adjNode] = 1;
                    visits++;
                }
            }
        }
        return false;
    }
};