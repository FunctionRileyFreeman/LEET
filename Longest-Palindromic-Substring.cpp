#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, end = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // Check for odd length palindromes
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Use the max length from above two checks
            int len = max(len1, len2);
            if (len > end - start) {
                // Update start and end to the new longest palindrome
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        
        // Extract the longest palindrome from the string
        return s.substr(start, end - start + 1);
    }
    
    // Helper function to return the length of the palindrome
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            // Expand around the center if the characters are equal
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
};
