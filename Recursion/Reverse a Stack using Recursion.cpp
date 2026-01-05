// REVERSE A STACK USING RECURSION
// Time Complexity - O(N^2)

#include<bits/stdc++.h>
using namespace std;

stack<int> st;

// Recursive function that inserts an element at the bottom of Stack.
void insert_at_bottom(int x){
    
    if (st.size() == 0) {         // Base Condition
        st.push(x);
        return;
    }

    int temp = st.top();             // storing the top element of the stack
    st.pop();

    insert_at_bottom(x);

    st.push(temp);                   // pushing the element 'a' after 'x' has been pushed in the stack
}

// Recursive Function to reverse Stack
void reverseStack() {

    if (st.size() == 1)        // Base Condtion (when Stack has only one element)
        return;

    int temp = st.top();       // storing the top element of the stack
    st.pop();

    reverseStack();            // calling recursively on smaller stack

    insert_at_bottom(temp);    // Recursive function that inserts an element at the bottom of a stack.
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
