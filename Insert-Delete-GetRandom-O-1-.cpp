#include <vector>
#include <unordered_map>
#include <cstdlib>

class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> valToIndex;

public:
    RandomizedSet() { }

    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        valToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }
        int lastElement = nums.back();
        int idxToRemove = valToIndex[val];
        nums[idxToRemove] = lastElement; // Move the last element to the place of the element to remove
        valToIndex[lastElement] = idxToRemove; // Update the moved element's index in the hash table
        nums.pop_back(); // Remove the last element
        valToIndex.erase(val); // Erase the removed element's index
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size(); // Generate a random index
        return nums[randomIndex]; // Return the element at the random index
    }
};
