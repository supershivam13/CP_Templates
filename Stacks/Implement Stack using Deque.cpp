class MyStack {
public:
    deque<int>q;
    MyStack() {}

    void push(int x) {
        q.push_back(x);

        int times = q.size() - 1;          // removing (q.size()-1) elements from the front and inserting them from the back,
        while (times--) {                  // so that stack property of LIFO is maintained
            q.push_back(q.front());
            q.pop_front();
        }
    }

    int pop() {
        int x = q.front();
        q.pop_front();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
