class MinStack {
private:
    stack<int> s;   // main stack
    stack<int> ss;  // supporting stack 'ss', always store minimum at top

public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);

        if(ss.size()==0 || ss.top()>=val)  // check if 'val' is needed to be insert in supporting stack 'ss' also
            ss.push(val);
    }
    
    void pop() {
        
        if(s.top()==ss.top())   // check if needed to pop from supporting stack 'ss' also
            ss.pop();
        
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();  // supporting stack 'ss' always stores the min value at top
    }
};
