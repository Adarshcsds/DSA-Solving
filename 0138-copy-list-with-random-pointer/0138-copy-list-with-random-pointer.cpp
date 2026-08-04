class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (!head)
            return nullptr;

        Node* curr = head;

        // Step 1: Insert copied nodes
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Set random pointers
        curr = head;

        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        // Step 3: Separate lists
        curr = head;

        Node* dummy = new Node(0);
        Node* copyCurr = dummy;

        while (curr) {

            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;

            curr->next = curr->next->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};