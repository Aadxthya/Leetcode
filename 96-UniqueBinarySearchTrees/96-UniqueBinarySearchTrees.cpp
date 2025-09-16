// Last updated: 9/16/2025, 9:54:03 AM
class Solution {
public:
    int numTrees(int n) {
      vector<int> catalanNo (n + 1, 0);
      catalanNo[0] = 1;

      for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < i; j++) {
          catalanNo[i] += catalanNo[j] * catalanNo[i - 1 - j];
        }
      }
        
      return catalanNo[n];
    }
};