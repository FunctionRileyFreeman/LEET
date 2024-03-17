#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // Start path from the top-left corner
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        
        // Fill in the first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 1) break;  // An obstacle blocks the path
            dp[0][j] = dp[0][j-1];
        }
        
        // Fill in the first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) break;  // An obstacle blocks the path
            dp[i][0] = dp[i-1][0];
        }
        
        // Fill in the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
