// Last updated: 9/16/2025, 9:52:31 AM
class Solution {
public:
    int hIndex(vector<int>& citations) {

     sort(citations.rbegin() , citations.rend());
    int n = citations.size();

     int j = 0 ; 
     for(int i = 0 ; i < n ; i++){
        if(citations[i] >= i + 1){
            j = i + 1 ; 
        }
        else{
            break;
        }

     }   

     return j ;
    }
};
