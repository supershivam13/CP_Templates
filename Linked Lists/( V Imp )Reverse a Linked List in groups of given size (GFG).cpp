/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/


class Solution {
public:
    struct node *reverse (struct node *head, int k)
    {
        // Base conditon ( either 0 or 1 nodes in list )
        if (head == NULL or head->next == NULL)
            return head;

        // variable to keep track of reversing k nodes only
        int cnt = 1;
        node* prev = NULL;
        node* curr = head;
        node* temp;

        while (curr != NULL and cnt <= k) {

            // stores next
            temp = curr->next;
            // update the current
            curr->next = prev;

            prev = curr;
            curr = temp;
            cnt++;
        }

        // list has more nodes than k, so reversing the next k nodes using recursion
        // and it returns the head of the reverse linked list
        if (curr != NULL) {
            head->next = reverse(curr, k);
        }

        // prev points to head element after reversing
        return prev;
    }
};
