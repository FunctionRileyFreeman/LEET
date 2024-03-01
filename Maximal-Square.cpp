#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSize = 0;
        
        // Initialize the first row and column.
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            maxSize = max(maxSize, dp[i][0]);
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            maxSize = max(maxSize, dp[0][j]);
        }
        
        // Fill in the rest of the dp table.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }
        
        // The area of the largest square is the square of the maximum side length.
        return maxSize * maxSize;
    }
};
