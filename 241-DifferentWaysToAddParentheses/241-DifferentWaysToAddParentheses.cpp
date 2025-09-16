// Last updated: 9/16/2025, 9:52:38 AM
class Solution {
public:
    unordered_map<string,vector<int>>memo;

    
    vector<int> diffWaysToCompute(string expression) {
        
        if(memo.find(expression)!=memo.end()){
            return memo[expression];
        }
        vector<int>res;
        for(int i=0;i<expression.size();i++){
           char ch=expression[i];

           if(ch=='+' || ch=='-' || ch=='*'){
            vector<int>left=diffWaysToCompute(expression.substr(0,i));
            vector<int>right=diffWaysToCompute(expression.substr(i+1));
            for(int l:left){
                for(int r:right){
                    if(ch=='+') res.push_back(l+r);
                   else if(ch=='-') res.push_back(l-r);
                    else if(ch=='*') res.push_back(l*r);

                }
            }
           }
           
           }
           if(res.empty()){
            res.push_back(stoi(expression));
        }
        memo[expression]=res;
        return res;
    }
};