class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<char>> visited(row, vector<char>(col, 'X')); // Extra space

        if (row < 3 || col < 3) return;

        queue<pair<int, int>> q;

        // Push boundary 'O' cells into the queue
        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O') { q.push({0, i}); visited[0][i] = 'O'; }
            if (board[row - 1][i] == 'O') { q.push({row - 1, i}); visited[row - 1][i] = 'O'; }
        }
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') { q.push({i, 0}); visited[i][0] = 'O'; }
            if (board[i][col - 1] == 'O') { q.push({i, col - 1}); visited[i][col - 1] = 'O'; }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // BFS traversal
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto &[dx, dy] : directions) {
                int x = r + dx, y = c + dy;
                if (x >= 0 && y >= 0 && x < row && y < col) {
                    if (board[x][y] == 'O' && visited[x][y] == 'X') {
                        visited[x][y] = 'O';
                        q.push({x, y});
                    }
                }
            }
        }

        board = visited;
    }
};
