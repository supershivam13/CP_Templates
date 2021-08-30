// Time Complexity - O(N + M)
// Space Complexity - O(N + M)

class Solution {
public:
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
};
