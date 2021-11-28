// It’s not difficult to realize that we need a stack so that back can be implemented.
// However, what to do for forward. Because you want the ability to visit all pages in the backward as well as
// the forward direction, we need to store the URLs whenever we go back. If you see the order in which we want to visit,
// you will quickly realize that we need two stacks.
// One to store history and another to store the next URLs in case we go back.


class BrowserHistory {
public:
    stack<string> history;
    stack<string> future;

    BrowserHistory(string homepage) {
        history.push(homepage);
        future = stack<string>();     // Reset the forward stack.
    }

    void visit(string url) {
        history.push(url);
        future = stack<string>();     // Reset the forward stack.
    }

    string back(int steps) {
        // You must always have at least one element in the history stack which is the page that you are currently at.
        while (steps > 0 and history.size() > 1) {
            future.push(history.top());
            history.pop();
            steps--;
        }

        return history.top();
    }

    string forward(int steps) {

        while (steps > 0 and future.size() > 0) {
            history.push(future.top());
            future.pop();
            steps--;
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
