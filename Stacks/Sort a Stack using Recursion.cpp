// SORT A STACK USING RECURSION
// ( Smallest element on top of stack)

// ************************************************************************************************

void insert(stack<int> st, int element) {

    // Base Condition OR element need to be stored at the top of the stack
    if (st.empty() || st.top() >= element)
        st.push(element);

    else {

        int temp = st.top();
        st.pop();

        // calling recursively on smaller stack to insert 'element' at the correct place
        insert(st, element);

        // then pushing back 'temp' in stack as temp < element, so 'temp' will be above than 'element' in stack
        st.push(temp);
    }
}

// Solution starts here
void sortedStack(stack<int> s) {

    // Base Condition
    if (s.size == 0)
        return;

    int temp = s.top();
    s.pop();

    // calling recursively on smaller stack
    sortedStack(s);

    // function to insert the temp element at the correct place in stack
    insert(s, temp);

}
