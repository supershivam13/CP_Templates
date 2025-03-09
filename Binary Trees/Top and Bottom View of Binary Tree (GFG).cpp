// For both Top and Bottom View
// Time Complexity - O( N*logN ){ logN is used in storing in map and N is for traversing every node one time}
// Space Complexity  - O(N) { as we are using a queue to store }



// *****************************************************************************************

// Top View of Binary Tree

// Should use Level Order Traversal (not any Pre,Post,In) in this question as Level order gives the first
// occurence of value at x-coordinate which is first as well as top element at that x-coordinate too.

class Solution {
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;

        // map of {x-cordinate, value} to store the only first occurence at each new value of x
        map<int, int> m;        // { x-cordinate : value}

        // Perform Level Order traversal
        queue<pair<Node*, int>> q;        // { Node*, x-cordinate }
        q.push({root, 0});

        while (q.size()>0) {

            Node* temp = q.front().first;
            int x = q.front().second;
            q.pop();

            // only store the first occurence of 'x' along with its value as {x,value}, rest not required
            if (m.find(x) == m.end())  // BOTTOM VIEW  = Just Remove this 'if' statement, rest all same as Top View
                m[x] = temp->data;        

            if (temp->left)
                q.push({temp->left, x - 1});
            if (temp->right)
                q.push({temp->right, x + 1});
        }

        for (auto p : m)            // map has all values as { x-cordinate : value}
            ans.push_back(p.second);

        return ans;
    }
};


// **************************************************************************************root

// Bottom View of Binary Tree

// Should use Level Order Traversal (not any Pre,Post,In) in this question as If there are multiple
// bottom-most nodes for a 'x, then we have to print the later one in level traversal


class Solution {
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;

        // map of {value,x-cordinate} to store the only last occurence at each value of x
        map<int, int> m;

        // Perform Level Order traversal
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {

            Node* temp = q.front().first;
            int x = q.front().second;
            q.pop();

            // Only difference with Top View is here, we are not checking any condition on map
            // we just keep on updating the values in map as we want the last or bottom view
            m[x] = temp->data;

            if (temp->left)
                q.push({temp->left, x - 1});
            if (temp->right)
                q.push({temp->right, x + 1});
        }

        for (auto p : m)
            ans.push_back(p.second);

        return ans;
    }
};
