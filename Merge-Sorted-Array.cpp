#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1;  // Last valid element index in nums1
        int idx2 = n - 1;  // Last element index in nums2
        int mergeIdx = m + n - 1;  // Index to put next largest element

        // Merge nums2 into nums1 starting from the end
        while (idx2 >= 0) {
            // If nums1 is exhausted, or nums2's element is larger
            if (idx1 < 0 || nums2[idx2] >= nums1[idx1]) {
                nums1[mergeIdx] = nums2[idx2];
                idx2--;
            } else {
                nums1[mergeIdx] = nums1[idx1];
                idx1--;
            }
            mergeIdx--;
        }
    }
};
