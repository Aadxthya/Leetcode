// Last updated: 9/16/2025, 9:53:07 AM
class Solution {
public:
    int trailingZeroes(int n) {
    int ans = 0;
    while(n > 0){
        n /= 5;
        ans += n;
    }
    return ans;
}

};