// Last updated: 9/16/2025, 9:53:16 AM
class MinStack {
    stack<int> st;
    stack<int> minst;

public:
    MinStack() {
        // No need to declare stacks here; they are already class members
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty() || val <= minst.top()) {
            minst.push(val);
        }
    }
    
    void pop() {
        if(st.top() == minst.top()) {
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
