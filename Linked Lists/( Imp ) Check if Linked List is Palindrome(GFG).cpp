class Solution {
public:
    // Function to return the length of a Linked List
    int length(Node* head) {

        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Iterative method Function to reverse a Linked List ( Time - O(N), Space - O(1) )
    // Returns the head(first node) of the Reversed Linked List
    Node* reverseList(struct Node *head)
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


    // SOLUTION STARTS HERE
    bool isPalindrome(Node *head)
    {
        // List of one node is always a palindrome
        if (head->next == NULL)
            return true;

        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL and fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        int l = length(head);

        // if length is even, then there will be two middle nodes
        // and we have to choose the second middle node
        if (l % 2 == 0)
            slow = slow->next;

        // Reversing the Linked List from the middle point
        Node* end = reverseList(slow);
        Node* start = head;

        while (end != NULL) {

            if (end->data != start->data)
                return false;

            start = start->next;
            end = end->next;
        }

        return true;
    }
};
