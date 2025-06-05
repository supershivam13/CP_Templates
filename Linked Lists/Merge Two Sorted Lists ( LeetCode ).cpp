// Method 1 - Iterative method ( similar to Merge two Sorted arrays )

 // TC - O(n+m)
 // SC - O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;    // 't' node to traverse further, 'dummy' node to store the head of the merged sorted list

        // Merge while both lists are non-empty
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                t->next = list1;
                list1 = list1->next;
            } 
            else {
                t->next = list2;
                list2 = list2->next;
            }
            t = t->next;
        }

        // Attach the remaining part  // Since it's linked list, just attaching one pointer will join the remaining list
        if (list1 != NULL) t->next = list1; 
        if (list2 != NULL) t->next = list2;

        return dummy->next; // Skip dummy node
    }
};




// Method 2 - Recursive Method

// Time Complexity - O(N + M)
// Space Complexity - O(N + M) ( to store the recursive calls in stack )

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        ListNode* result;

        // SORTING THE LISTS RECURSIVELY
        if (a->val < b->val) {
            result = a;
            result->next = mergeTwoLists(a->next, b);
        }
        else {
            result = b;
            result->next = mergeTwoLists(a, b->next);
        }

        return result;
    }
};
