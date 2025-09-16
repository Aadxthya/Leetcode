// Last updated: 9/16/2025, 9:48:38 AM
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
       int n=skill.size();
       sort(skill.begin(),skill.end());

       vector<int>ans;
       long long sum=0;
       int l=0;
       int h=n-1;
       long long  target=skill[l]+skill[h];

       while(l<=h){

        if(skill[l]+skill[h]==target){
           ans.push_back( skill[l]*skill[h]);
           l++;
           h--;
        }
       else{
       return -1;
       }
        

       }
       for(int i=0;i<ans.size();i++){
       
        sum+=ans[i];
       }
       return sum;
    }
};