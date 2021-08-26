// Time Complexity - O(N) { instead of two nested while loops, the complexity is O(N) }



vector<int> leftView(Node *root)
{
    vector<int> ans;
    queue<Node*> q;

    if (root == NULL)
        return ans;

    q.push(root);

    // Run till the queue gets empty
    while (!q.empty()) {

        // size will be equal to the nodes in that level of the tree
        int size = q.size();

        // storing the first element of each level of tree
        ans.push_back(q.front()->data);

        // processing the nodes level-wise
        while (size--) {
            Node* temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    return ans;
}
