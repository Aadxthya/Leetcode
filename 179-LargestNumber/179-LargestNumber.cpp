// Last updated: 9/16/2025, 9:53:04 AM
class Solution {
public:

    static bool cmp(const string& a , const string& b){
       return  a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int num: nums){
            str.push_back(to_string(num));

        }

        sort(str.begin(), str.end() , cmp);

        if(str[0]=="0") return "0";

        string res;
        for(auto &s : str ) res += s;

        return res;
    }
};