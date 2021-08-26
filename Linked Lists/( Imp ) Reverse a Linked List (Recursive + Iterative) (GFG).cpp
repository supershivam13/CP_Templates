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
        // { Prev Curr Temp }
        Node* prev = NULL;
        Node* curr = head;
        Node* temp;

        while (curr != NULL) {

            // store next
            temp = curr->next;

            // update current
            curr->next = prev;

            prev = curr;
            curr = temp;
        }

        head = prev;

        return head;
    }
};