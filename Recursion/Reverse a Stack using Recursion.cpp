// REVERSE A STACK USING RECURSION

// ************************************************************************************************

#include<bits/stdc++.h>
using namespace std;

stack<int> st;


// recursive function that inserts an element at the bottom of a stack.
void insert_at_bottom(int x)
{
    // Base Condition
    if (st.size() == 0) {
        st.push(x);
        return;
    }

    // storing the top element of the stack
    int a = st.top();
    st.pop();

    insert_at_bottom(x);

    // pushing the element 'a' after 'x' has been pushed in the stack
    st.push(a);
}


// Recursive function to reverse Stack
void reverseStack() {

    // Base Condtion ( when stack has only one element, nothing to be done )
    if (st.size() == 1)
        return;

    // storing the top element of the stack
    int temp = st.top();
    st.pop();

    // calling recursively on smaller stack
    reverseStack();

    // recursive function that inserts an element at the bottom of a stack.
    insert_at_bottom(temp);
}


int main()
{
    // push elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    // function to reverse the stack
    reverseStack();

    // Printing the reversed stack
    while (!st.empty())
    {
        int temp = st.top();
        cout << temp << " ";
        st.pop();
    }

}
