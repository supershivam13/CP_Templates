// Method - 1 {Better  Method}

// Time Complexity - O(N)
// Space Complexity - O(1) ( we are not using any extra space in this )

class Solution {
public:
    // function to return the length of a linked list
    int length(ListNode* head) {

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Solution starts here
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (headA == NULL)
            return headB;
        if (headB == NULL)
            return headA;

        int l1 = length(headA);
        int l2 = length(headB);

        int d = 0;
        ListNode* big;
        ListNode* small;

        if (l1 >= l2) {
            d = l1 - l2;
            big = headA;
            small = headB;
        }
        else {
            d = l2 - l1;
            big = headB;
            small = headA;
        }

        // moving the big pointer 'd' steps ahead
        while (d--)
            big = big->next;

        // big and small are at equal distance from the point of intersection (if any)
        while (big != NULL and small != NULL) {
            if (big == small)
                return big;

            big = big->next;
            small = small->next;
        }

        // else there is no point of intersection
        return NULL;
    }
};


// ***********************************************************************************


// Method - 2 ( Using Sets ){Easy Method}

// Time Complexity - O(N)
// Space Complexity - O(N) { used in making set<ListNode*> }

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        set<ListNode*> s;

        if (headA == NULL)
            return headB;
        if (headB == NULL)
            return headA;

        // insert all the nodes of list 1 in set
        while (headA != NULL) {
            s.insert(headA);
            headA = headA->next;
        }

        // if any node of list 2 already existed in set, then that node is point of intersection
        while (headB != NULL) {

            if (s.find(headB) != s.end())
                return headB;

            headB = headB->next;
        }

        // else there is no point of intersection
        return NULL;

    }
};
