#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int m = board.size(), n = board[0].size();

        // First pass to compute the next state using the second bit.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        liveNeighbors += board[x][y] & 1; // Only the least significant bit contributes to the live count.
                    }
                }
                if (board[i][j] & 1) {
                    if (liveNeighbors >= 2 && liveNeighbors <= 3) {
                        board[i][j] |= 2; // Set the second bit if the cell lives on.
                    }
                } else {
                    if (liveNeighbors == 3) {
                        board[i][j] |= 2; // Set the second bit if the cell becomes alive.
                    }
                }
            }
        }

        // Second pass to update the board to the next state.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1; // Shift the bits to the right to get the next state.
            }
        }
    }
};
