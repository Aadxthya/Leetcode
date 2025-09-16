// Last updated: 9/16/2025, 9:48:00 AM
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long >prefix(k);
        prefix[0]=nums[0];
        for(int i=1;i<k;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        long long ans;
        long long sum=ans=prefix[k-1]; 
        if(prefix[k-1]>0)  
            prefix[k-1]=0;   
       // cout<<sum<<endl;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
          //  cout<<sum<<endl;
            ans=max(ans,sum-prefix[i%k]);
            prefix[i%k]=min(prefix[i%k],sum);
        }
        return ans;
    }
};