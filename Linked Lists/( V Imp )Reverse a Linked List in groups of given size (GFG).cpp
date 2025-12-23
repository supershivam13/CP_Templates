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
        
        // PCT { prev curr temp }
        node* prev = NULL;
        node* curr = head;
        node* temp;

        int cnt = 1;        // variable to keep track of reversing k nodes only

        while (curr != NULL && cnt <= k) {
           
            temp = curr->next;                 // stores next node in 'temp'  // { TCP }
            curr->next = prev;                 // update curr

            prev = curr;          // P = C      // { PCT }
            curr = temp;          // C = T
            cnt++;
        }

        // list has more nodes than k, so reversing the next k nodes using Recursion
        // and it returns the head of the reverse linked list
        if (curr != NULL)
            head->next = reverse(curr, k);

        // prev points to head element after reversing
        return prev;
    }
};
