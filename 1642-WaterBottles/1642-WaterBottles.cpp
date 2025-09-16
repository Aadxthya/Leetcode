// Last updated: 9/16/2025, 9:49:42 AM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        while(empty >= numExchange){
            int n = empty/numExchange;
            int m = empty%numExchange;
            empty = m + n;
            numBottles = numBottles + n; 
        }
        return numBottles;
    }
};