// Last updated: 9/16/2025, 9:55:33 AM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

       sort(nums.begin(), nums.end());
        int n = nums.size();
vector<vector<int>> ans;
       for(int i = 0 ; i<n ; i++ ){
        int j = i + 1;
        int k = n - 1;
        if(i > 0 && nums[i]==nums[i -1]){
            continue;


        }
        

        while( j < k){
          int summ =  nums[i] + nums[j] + nums[k] ;



          if ( summ< 0){
            j++;
          }

          else if( summ > 0){
            k--;
          }
          else{
            ans.push_back({nums[i], nums[j], nums[k]});
            j++;
            k--;
          
 while(j < k && nums[j] == nums[j - 1]) j++;     // skip duplicates of nums[j]
    while(j < k && nums[k] == nums[k + 1]) k--;     // skip duplicates of nums[k]
        }
        }

       }
return ans;
    }
};