// variable to store the min element at any point of time
long long min_ele;

class MinStack {

private:
    stack< long long> s;

public:

    void push(long long val) {

        // when stack is empty, then directly push the element and make it as min_ele
        if (s.size() == 0) {
            s.push(val);
            min_ele = val;
        }
        else {
            // if value to be pushed is greater than min_ele, then simply push
            if (val >= min_ele)
                s.push(val);

            else {
                // pushing corrupt data((val*2)- min_ele) which acts as a flag to indicate that
                // it's the minimum element of the stack and correct value is present in min_ele

                // ((val*2)- min_ele) is smaller than min_ele itself indicating that it's the place
                // for the minimum element in stack and correct value is present in min_ele
                s.push((val * 2) - min_ele);
                min_ele = val;
            }
        }

    }

    void pop() {

        // if stack is empty, then do nothing
        if (s.size() == 0)
            return;
        else {
            // if element to be popped is smaller then min_ele, then simply pop
            if (s.top() >= min_ele)
                s.pop();

            // if element to be popped is even smaller than min_ele itself indicating that it's the place
            // for the minimum element in stack and correct value is present in min_ele

            // now it's the mechanism to retreive back the last(previous) min element and store it in min_ele
            // some sort of reverse mechanishm of ((val*2)- min_ele)
            else {
                min_ele = (min_ele * 2) - s.top();
                s.pop();
            }
        }
    }

    int top() {

        if (s.size() == 0)
            return -1;

        // if top element is greater or equal to min_ele, then simply return s.top()
        if (s.top() >= min_ele)
            return s.top();
        else
            // means corrupt data is present on top and correct value is present in min_ele
            return min_ele;
    }

    int getMin() {

        if (s.size() == 0)
            return -1;

        return min_ele;
    }
};
