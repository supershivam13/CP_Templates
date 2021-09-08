class MinStack {

private:
    stack<int> s;
    // supporting stack
    stack<int> ss;
    
public:
    
    void push(int val) {
        s.push(val);
        
        if(ss.size()==0 or ss.top()>=val)
            ss.push(val);
    }
    
    void pop() {
        
        if(ss.top()==s.top())
            ss.pop();
        
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};
