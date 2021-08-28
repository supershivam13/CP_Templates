// Should use Level Order Traversal (not any Pre,Post,In) in this question as Level order gives the first
// occurence of value at x-coordinate which is first as well as top element at that x-coordinate too.

class Solution {
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;

        // map of {value,x-cordinate} to store the only first occurence at each new value of x
        map<int, int> m;

        // Perform Level Order traversal
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {

            Node* temp = q.front().first;
            int x = q.front().second;
            q.pop();

            // only store the first occurence of 'x' along with its value as {value,x}
            if (m.find(x) == m.end())
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
