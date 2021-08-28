// Solution to LeetCode :

// Question Clarification -
// Among all nodes which are in the same line vertically, those node who occur before in level order
// traversal should come first and the nodes which occur in the same level should be sorted.


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        // map of {x-cordinate, {y-cordinate,values} } to store the nodes at a particular 'x'
        // and 'y' coordinate
        map<int, map<int, vector<int>>> m;

        if (root == NULL)
            return ans;

        // Perform Level Order traversal
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {

            TreeNode* temp = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            m[x][y].push_back(temp->val);

            if (temp->left)
                q.push({temp->left, {x - 1, y + 1}});
            if (temp->right)
                q.push({temp->right, {x + 1, y + 1}});
        }

        // Storing the results in 'ans' vector as per the question
        for (auto col : m) {
            vector<int> v;

            for (auto row : col.second) {
                vector<int> v1 = row.second;
                sort(v1.begin(), v1.end());

                v.insert(v.end(), v1.begin(), v1.end());
            }

            ans.push_back(v);
        }

        return ans;
    }
};



// ************************************************************************************


// Solution to GFG :

// Question Clarification -
// Among all nodes which are in the same line vertically, they should be printed as they appear in
// level order traversal of the tree

// Should use Level Order Traversal (not any Pre,Post,In) in this question as it demands to print
// nodes in level-order fashion for same vertical line.

class Solution {
public:
    vector<int> verticalOrder(Node *root)
    {
        // map of {x-cordinate, values} to store the nodes at a particular 'x' coordinate
        map<int, vector<int>> m;
        vector<int> ans;

        // Perform Level Order traversal
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {

            Node* temp = q.front().first;
            int x = q.front().second;
            q.pop();

            // storing the nodes with their respective 'x' coordinate
            m[x].push_back(temp->data);

            if (temp->left)
                q.push({temp->left, x - 1});
            if (temp->right)
                q.push({temp->right, x + 1});

        }

        // Getting all the nodes in one vector 'ans' to return
        // Map contains the vertical levels stored in sorted order
        for (auto level : m) {

            for (auto ele : level.second)
                ans.push_back(ele);

        }

        return ans;
    }
};
