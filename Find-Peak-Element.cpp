#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                // If mid element is greater than the next element, then a peak must be in the left half,
                // including the mid element itself.
                right = mid;
            } else {
                // If mid element is less than the next element, then a peak exists in the right half,
                // excluding the mid element.
                left = mid + 1;
            }
        }
        // When left == right, we have found the peak element.
        return left;
    }
};
