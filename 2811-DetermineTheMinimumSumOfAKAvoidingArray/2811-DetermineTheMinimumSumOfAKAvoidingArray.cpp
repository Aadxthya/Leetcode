// Last updated: 9/16/2025, 9:48:25 AM
class Solution {
public:
    int solve(int a,int n){
        return (a+a+n-1)*n/2;   // n/2*(2a+(n-1)*d)
    }
    int minimumSum(int n, int k) {
        int num=min(n,k/2);
        return solve(1,num)+solve(k,n-num);
    }
};