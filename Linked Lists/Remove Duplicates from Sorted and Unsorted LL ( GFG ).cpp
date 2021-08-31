// FOR SORTED LINKED LIST

// Time Complexity - O(N)
// Space Complexity - O(1)

Node *removeDuplicates(Node *head)
{
    // Base Case ( 0 or 1 nodes only )
    if (head == NULL or head->next == NULL)
        return head;

    // keeping the head pointer stored in 'head2' to return at the end
    Node* head2 = head;

    while (head->next != NULL) {

        if (head->data == head->next->data)
            head->next = head->next->next;
        else
            head = head->next;
    }

    return head2;
}


// *************************************************************************************


// FOR UN-SORTED LINKED LIST

// Time Complexity - O(N)
// Space Complexity - O(N) { used in making map }


class Solution {
public:
    Node * removeDuplicates( Node *head)
    {
        // Base Case ( 0 or 1 nodes only )
        if (head == NULL or head->next == NULL)
            return head;

        Node* cur = head;
        Node* prev = NULL;

        // map to keep track of the elements already occured ans inserting the first element
        map<int, int> m;
        m[cur->data]++;
        prev = cur;

        // Always do this, cur always points to the next of prev, not of itself ( Wrong : cur = cur->next )
        cur = prev->next;

        while (cur != NULL) {

            // if already found, make 'prev' a jump of one node
            if (m[cur->data] > 0) {
                prev->next = cur->next;
                free(cur);
            }
            else {
                m[cur->data]++;
                prev = cur;
            }

            cur = prev->next;
        }

        return head;
    }
};
