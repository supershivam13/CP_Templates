class MinStack {

private:
    stack<int> s;     // normal stack 's'
    stack<int> ss;    // supporting stack 'ss', always stores the min value at top
    
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
        return ss.top();   // supporting stack 'ss' always stores the min value at top
    }
};
