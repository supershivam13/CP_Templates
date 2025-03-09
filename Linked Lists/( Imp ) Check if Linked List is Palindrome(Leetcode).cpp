/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Function to return the length of a Linked List
    int length(ListNode* head) {

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Iterative method Function to reverse a Linked List ( Time - O(N), Space - O(1) )
    // Returns the head(first node) of the Reversed Linked List
    ListNode* reverseList(struct ListNode *head)
    {
        // { Prev Curr Temp }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp;

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
    bool isPalindrome(ListNode *head)
    {
        // List of one node is always a palindrome
        if (head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL and fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // After this loop, 'slow' points to the MIDDLE of the linked list
        // in case of even length linked list, there will be two middle nodes, slow points to second middle node

        // Reversing the Linked List from the middle point
        ListNode* end = reverseList(slow);      // second of the Linked list is reversed
        ListNode* start = head;

        while (end != NULL) {   // simply traversing from 'start' and 'end' and checking if data is equal or not

            if (end->val != start->val)
                return false;

            start = start->next;
            end = end->next;
        }

        return true;
    }
};
