// Floyd's Algorithm ( Tortoise and Rabbit Algorithm )
// ( Apni Kaksha YT )


class Solution {
public:
    void removeLoop(Node* head)
    {
        bool hasCycle = false;
        Node* fast = head;
        Node* slow = head;

        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // if it has cycle, then this condition will surely reach
            // (since fast is moving 2X of slow, ideally it should never be equal,
            // but if they become equal, then it confirms the presence of cycle )
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }

        if (hasCycle == false)
            return;

        // Putting the fast pointer to the head
        fast = head;

        // Case 1 (Edge Case) - when the cycle starts with head included in cycle
        // Move slow pointer to the last node (just before the head) and make slow->next = NULL
        if (slow == head) {

            do {
                slow = slow->next;
            } while (slow->next != fast);

            slow->next = NULL;

        }
        // Case 2 - when the cycle starts somewhere ahead of head
        // Move slow and fast with same speed till their nexts point to the same node and make slow->next = NULL
        else {

            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            slow->next = NULL;
        }

    }
};
