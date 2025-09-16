// Last updated: 9/16/2025, 9:53:11 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {


        unordered_map<int,int> mpp;
         
        for(int i = 0;i<numbers.size();i++){
            int complomnet = target - numbers[i];

            if(mpp.find(complomnet)!= mpp.end()){
                return{mpp[complomnet] + 1,i + 1};
            }
            mpp[numbers[i]]=i;
        }
        return{};

    }    
};