// REVERSE A STACK USING RECURSION
// Time Complexity - O(N^2)

#include<bits/stdc++.h>
using namespace std;

// Recursive function that inserts an element at the bottom of Stack.
void insert_at_bottom(stack<int>& st, int x){
    if (st.size() == 0) {            // Base Condition
        st.push(x);
        return;
    }

    int temp = st.top();             // storing the top element of the stack
    st.pop();

    insert_at_bottom(st, x);

    st.push(temp);                   // pushing the element 'a' after 'x' has been pushed in the stack
}

// CODE starts here (Recursive Function to reverse Stack)
void reverseStack(stack<int>& st) {
    if (st.size() == 1)        // Base Condtion (when Stack has only one element)
        return;

    int temp = st.top();       // storing the top element of the stack
    st.pop();

    reverseStack(st);            // calling recursively on smaller stack
    insert_at_bottom(st, temp);    // Recursive function that inserts an element at the bottom of a stack.
}

int main(){
    stack<int> st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    reverseStack(st);                  // Function to reverse the stack

    while (st.size() > 0){           // Printing the reversed stack
        int temp = st.top();
        st.pop();
        cout << temp << " ";
    }
}
