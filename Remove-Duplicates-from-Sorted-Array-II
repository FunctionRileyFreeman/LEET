class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n; // If the array has less than 3 elements, all of them are kept.

        int k = 2; // Start from the third element
        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[k - 2]) { // Check if the current element is different from the element two positions back.
                nums[k] = nums[i]; // If so, it's safe to include this element.
                k++;
            }
        }
        return k; // The new length of the array without extra duplicates.
    }
};
