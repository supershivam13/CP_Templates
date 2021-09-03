// Implement Stack using 2 Queues

// Push - O(N)
// Pop - O(1)


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */


void QueueStack :: push(int x)
{
    q1.push(x);
    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
    swap(q1, q2);

    // After all this, all elements will be stored in q2 which are ready to be popped
}

int QueueStack :: pop()
{
    // q2 is used only in the pop() operation as after push, all elements are finally gets stored in q2
    int ans;
    if (q2.empty()) {
        ans = -1;
    }
    else {
        ans = q2.front();
        q2.pop();
    }

    return ans;
}


// *****************************************************************

// Implement Stack using 1 Queue only (No extra space should be used)

// Push - O(N)
// Pop - O(1)


//Function to push an element into stack using one queue.
void QueueStack :: push(int x)
{
    q1.push(x);
    // removing (q.size()-1) elements from the front and inserting them from the back
    // so that stack property of LIFO is maintained
    int sz = q1.size() - 1;
    while (sz--) {
        q1.push(q1.front());
        q1.pop();
    }
}


//Function to pop an element from stack using one queue.
int QueueStack :: pop()
{
    int ans;
    if (q1.empty()) {
        ans = -1;
    }
    else {
        ans = q1.front();
        q1.pop();
    }

    return ans;
}
