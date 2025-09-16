// Last updated: 9/16/2025, 9:49:43 AM
class Solution {
public:  

    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {

            sort(nums.begin(),nums.end());
            int n = nums.size();
            int i = 0, j = n-1;
            int count = 0;

            vector<int> power(n);
            power[0]=1;
            for(int i=1;i<n;i++){
                power[i] = (power[i-1]*2)%M;
            }

            while(i<=j){

                int sum = nums[i] + nums[j];
                if(sum<=target){
                    int diff = j-i;
                    count = (count%M) + power[diff]%M;
                    i++;
                }
                else j--;

            }

            return (int)count;
        
    }
};