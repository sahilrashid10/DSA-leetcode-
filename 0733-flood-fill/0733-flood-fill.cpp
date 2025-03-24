class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {


        int row = image.size();
        int col = image[0].size();

        queue<pair<int, int>> q;
        int org = image[sr][sc]; 
        if(org == color) return image;
        image[sr][sc] = color;
        q.push({sr,sc});

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto &[dx, dy] : dir){
                int x = r + dx;
                int y = c + dy;
                if(x>=0 && y>=0 && x<row && y<col){
                    if(image[x][y] == org){
                        image[x][y] = color;
                        q.push({x, y});
                    }
                }
            }
        }
        return image;
    }
};