#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, current_jump_end = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == current_jump_end) {
                jumps++;
                current_jump_end = farthest;
            }
        }
        return jumps;
    }
};
