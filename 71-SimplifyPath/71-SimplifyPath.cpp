// Last updated: 9/16/2025, 9:54:30 AM
class Solution {
public:
    string simplifyPath(string path) {
        string h="";
        stack<string> st;
        for(int i=1; i<path.size(); i++){
            if(path[i] == '/' && path[i-1] == '/') continue;
            if(path[i] != '/') {h+=path[i];}
            if(path[i] == '/' || i == path.size() -1) 
            {
                if(h == ".") {}
                else if(h == "..") {if(!st.empty())st.pop();}
                else{
                    st.push(h);
                }
                h="";
            }
            
        }
        // cout<<h;
        // if(h!="/" && h!="." && h!="" && h!="..")st.push(h);
        string f="";
        if(st.empty()) return "/";
        while(!st.empty()){
            f = st.top() + f;
            f ="/" + f;
            
            st.pop();
        }
        return f;
    }
};