class MyStack {
public:

    deque<int>q;
    MyStack() {

    }

    // removing (q.size()-1) elements from the front and inserting them from the back
    // so that stack property of LIFO is maintained
    void push(int x) {
        q.push_back(x);

        int sz = q.size() - 1;
        while (sz--) {
            q.push_back(q.front());
            q.pop_front();
        }
    }

    // Removes the element on top of the stack and returns that element.
    int pop() {

        int x = -1;
        if (!q.empty())
        {
            x = q.front();
            q.pop_front();
        }
        return x;
    }

    int top() {
        if (!q.empty())
            return q.front();
        else
            return -1;
    }

    bool empty() {
        return q.empty() == true ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
