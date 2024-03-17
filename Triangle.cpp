#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Start from the second last row and move upwards
        for (int row = triangle.size() - 2; row >= 0; --row) {
            for (int i = 0; i <= row; ++i) {
                // Update the current cell with the sum of the cell and the minimum of its two children
                triangle[row][i] += min(triangle[row + 1][i], triangle[row + 1][i + 1]);
            }
        }
        // The top element of the triangle now contains the minimum path sum
        return triangle[0][0];
    }
};
