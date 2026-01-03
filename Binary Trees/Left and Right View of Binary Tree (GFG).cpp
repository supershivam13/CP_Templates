// 1) LEFT VIEW
// Time Complexity - O(N) { instead of two nested while loops, the complexity is O(N) }

class Solution {
  public:
    vector<int> leftView(Node *root){
        
        vector<int> ans;
        queue<Node*> q;

        if (root == NULL)
            return ans;

        q.push(root);           

        while (q.size() > 0) {

            int size = q.size(); //  Snippet - (1) size will be equal to the nodes in that level of the tree, and declare a temp pointer
            Node* temp;

            ans.push_back(q.front()->data); //  Snippet - (2) storing the first element of each level of tree

            // processing the nodes level-wise
            while (size--) {                // Snippet -  (3) While loop
                temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        return ans;
    }
};


// 2) RIGHT VIEW  ( only swap positions of Snippet (2) and (3) in Leftview to get Rightview)

// Time Complexity - O(N) { instead of two nested while loops, the complexity is O(N) }

class Solution {
public:
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        queue<Node*> q;

        if (root == NULL)
            return ans;

        q.push(root);

        while (q.size() > 0) {         // Run till the queue gets empty

            int size = q.size();   // Snippet - (1) size will be equal to the nodes in that level of the tree, and declare a temp pointer
            Node* temp;
            
            // processing the nodes level-wise
            while (size--) {            // Snippet - (2) while loop
                temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            // address of last element of each level will be remain stored in the 'temp' pointer
            // so, storing the last element of each level of tree
            ans.push_back(temp->data);        // Snippet - (3) storing the first element of each level of tree
        }

        return ans;
    }
};
