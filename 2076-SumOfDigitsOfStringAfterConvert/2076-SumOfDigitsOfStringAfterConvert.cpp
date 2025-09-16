// Last updated: 9/16/2025, 9:49:21 AM
class Solution {
public:
    int getLucky(string s, int k) {
        string num="";
        for(auto it:s){
            num+=to_string(it-'a'+1);
        }
        int sum=0;
        for(auto it:num){
            sum+=it-'0';
        }
        while(k>1){
            int ans=0;
            while(sum>0){
                ans+=sum%10;
                sum/=10;
            }
            sum=ans;
            k--;
        }
        return sum;
        
    }
};