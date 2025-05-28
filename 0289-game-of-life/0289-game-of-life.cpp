class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
         int m = board.size(), n = board[0].size();

        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        // First pass: mark changes with intermediate states
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;

                for (auto [dx, dy] : directions) {
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                        (board[ni][nj] == 1 || board[ni][nj] == -1)) {
                        liveNeighbors++;
                    }
                }

                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = -1;  // Alive → Dead
                }
                if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 2;   // Dead → Alive
                }
            }
        }

        // Second pass: finalize state changes
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};