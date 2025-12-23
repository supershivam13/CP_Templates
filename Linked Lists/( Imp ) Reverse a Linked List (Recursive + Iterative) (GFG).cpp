/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

// METHOD 1 - USING RECURSION
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    struct Node* reverseList(struct Node *head)
    {
        // Base Condition ( either 0 or 1 node only )
        if (head == NULL or head->next == NULL)
            return head;

        // Recursive call to reverse smaller linked list and return the head of the reversed list
        Node* RevHead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return RevHead;
    }
};


// METHOD 2 - ITERATIVE { without RECURSION }
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    struct Node* reverseList(struct Node *head)
    {
        // PCT { prev curr temp }
        Node* prev = NULL;
        Node* curr = head;
        Node* temp;

        while (curr != NULL) {

            temp = curr->next;        // stores next node in 'temp' // {TCP}
            curr->next = prev;        // update curr

            prev = curr;            // P = C        {PCT}
            curr = temp;            // C = T 
        }

        return prev;
    }
};
