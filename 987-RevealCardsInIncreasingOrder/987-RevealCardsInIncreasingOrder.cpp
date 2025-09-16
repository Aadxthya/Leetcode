// Last updated: 9/16/2025, 9:50:21 AM
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        deque<int> due;
        for (int i = 0; i < n; i++) {
            due.push_back(i);  
        }
        
        vector<int> result(n);
        int step = 1; // We start with a step 1 (revealing the top card)
        
        while (!due.empty()) {
            int front = due.front();
            due.pop_front();
            if (step == 1) {
                result[front] = deck.front();
                deck.erase(deck.begin());
            } else {
                due.push_back(front);
            }
            step = (step == 1) ? 0 : 1;
        }
        
        return result;
    }
};
