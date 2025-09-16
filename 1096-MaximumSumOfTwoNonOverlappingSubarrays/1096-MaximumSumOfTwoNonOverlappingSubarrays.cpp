// Last updated: 9/16/2025, 9:50:12 AM
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int l, int m) {
	int n = nums.size();
	vector<int> prefixSum(n+1, 0);
	int maxSum = 0;
	
	//building the prefix sums
	prefixSum[0] = 0;
	for(int i = 1; i<=n; i++) {
		prefixSum[i] = prefixSum[i-1] + nums[i-1];
	}
	
	//selecting the l length subarray
	for(int i = 0; i<=n-l; i++) {
		int lsum = prefixSum[i+l] - prefixSum[i];
		
		//looking left
		for(int j = 0; j<=i-m; j++) {
			int msum = prefixSum[j+m] - prefixSum[j];
			maxSum = max(maxSum, lsum + msum);
		}
		
		//looking right 
		for(int j = i+l; j<=n-m; j++) {
			int msum = prefixSum[j+m] - prefixSum[j];
			maxSum = max(maxSum, lsum + msum);
		}
	}
	return maxSum;
}
};