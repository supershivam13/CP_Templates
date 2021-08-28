// Idea to solve :
// Do Level-Order Traversal and keep a track of the current level, On reaching the k-th level,
// add all the nodes and break after that.

// Time Complexity: O(N)


class Solution {
public:
    int SumOfKthLevel(Node* root, int k) {

        int ans = 0;
        queue<Node*> q;

        if (root == NULL)
            return 0;

        int flag = 0;
        int cur_lev = 0;

        q.push(root);

        // Run till the queue gets empty
        while (!q.empty()) {

            // size will be equal to the nodes in that level of the tree
            int size = q.size();

            // processing the nodes level-wise
            while (size--) {

                Node* temp = q.front();
                q.pop();

                // Reached the k-th level, add up all the nodes data and make flag = 1 indicating
                // we've reached the k-th level, no need to go on
                if (cur_lev == k) {
                    flag = 1;
                    ans += (temp->data);
                }

                else {
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
            }

            cur_lev++;

            // Break out from the loop after the sum of nodes at K-th level is found
            if (flag == 1)
                break;
        }

        return ans;
    }
};
