// Last updated: 9/16/2025, 9:54:14 AM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea=0;
        int n = heights.size();
        for(int i = 0; i < heights.size(); i++){
        while(!st.empty() && heights[st.top()]> heights[i]){
            int topele = heights[st.top()];
            st.pop();
            int ste = !st.empty()?st.top() : -1;
            int area = topele*(i- ste - 1 ) ;
            maxarea = max(maxarea , area);

        }
        
        st.push(i);
        }

        while(!st.empty()){
            int topele = heights[st.top()];
            st.pop();
            int ste = !st.empty()?st.top() : -1;
            int area = topele*(n - ste - 1 ) ;
            maxarea = max(maxarea , area);
        }
    return maxarea;
    }
};