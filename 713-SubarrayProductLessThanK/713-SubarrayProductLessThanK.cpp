// Last updated: 9/16/2025, 9:51:10 AM
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //window method pa
        /*reee*/
        //initiate da which anol, hmm i j ? sum? enuf?
        //for loop or while?
        int i = 0;
        int sum = 0;
                    int total = 1;

        int n = nums.size();
        for(int j= 0;j<n;j++){
            total *= nums[j];
            while (total>=k && i<= j){
                total = total/nums[i];
                i++;
                
            }

            sum += j-i+1;
            

            }
            
                return sum;

        }

    };
