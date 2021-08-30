// Time Complexity - O( NlogN )

class Solution {
public:
    // Function to merge two sorted linked lists and return the head node pointer
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

        // if either one list is empty, return the other list
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        ListNode* c;

        // SORTING THE LISTS RECURSIVELY
        if (a->val < b->val)
            c = a, c->next = mergeTwoLists(a->next, b);
        else
            c = b, c->next = mergeTwoLists(a, b->next);

        return c;
    }


    // Function to return the mid point of the linked list
    ListNode* midpoint(ListNode *head) {

        if (head == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL and fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }


    // MERGE SORT FUNCTION
    ListNode* MergeSort(ListNode* head) {

        // If list has 0 or 1 nodes only ( Base Condition )
        if (head == NULL or head->next == NULL)
            return head;

        // 3 Steps -
        // 1. Divide
        // 2. Sort
        // 3. Merge

        // finding the midpoint of the list
        ListNode* mid = midpoint(head);

        ListNode* a = head;
        ListNode* b = mid->next;

        // 1) Dividing the linked list in two halves
        mid->next = NULL;

        // 2) Calling MergeSort recursively on both halves of the list
        a = MergeSort(a);
        b = MergeSort(b);

        // 3) this function returns the head of the node after merging two sorted lists
        return mergeTwoLists(a, b);
    }


    // Solution starts here
    ListNode* sortList(ListNode* head) {

        return MergeSort(head);
    }
};
