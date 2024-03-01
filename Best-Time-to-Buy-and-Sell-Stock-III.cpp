#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;
        
        for (int price : prices) {
            // Update firstBuy to be the smaller of itself and -price
            firstBuy = max(firstBuy, -price);
            // Update firstSell to be the larger of itself and price + firstBuy
            firstSell = max(firstSell, price + firstBuy);
            // Update secondBuy to be the larger of itself and firstSell - price
            secondBuy = max(secondBuy, firstSell - price);
            // Update secondSell to be the larger of itself and price + secondBuy
            secondSell = max(secondSell, price + secondBuy);
        }
        
        return secondSell; // This will be the maximum profit with at most two transactions.
    }
};
