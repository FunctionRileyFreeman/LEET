#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_reachable) {
                // If the current position is greater than the maximum reachable index,
                // it is not possible to move forward.
                return false;
            }
            // Update the maximum reachable index if the current index plus jump length is greater.
            max_reachable = max(max_reachable, i + nums[i]);
            if (max_reachable >= nums.size() - 1) {
                // If the maximum reachable index is at or beyond the last index, you can reach the end.
                return true;
            }
        }
        return false;
    }
};
