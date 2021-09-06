// Only two minor changes in Level Order Traversal to make it Reverse Level Order Traversal

// a) right sub-tree is processed first instead of left sub-tree
// b) need to revese the final vector to get the correct Reverse Level Order Traversal


// *******************************************************************************************

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;

    // Queue used in BFS ( Level Order Traversal == BFS )
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* curr = q.front();
        q.pop();

        ans.push_back(curr->data);

        // a) In Reverse Level Order Traversal, right sub-tree is processed first instead of left sub-tree
        if (curr->right != NULL)
            q.push(curr->right);

        if (curr->left != NULL)
            q.push(curr->left);
    }

    // b) reverse the vector to get the correct Reverse Level Order Traversal
    reverse(ans.begin(), ans.end());
    return ans;
}
