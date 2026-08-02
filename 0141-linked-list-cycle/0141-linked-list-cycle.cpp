class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        while (head != nullptr) {
            if (visited.count(head))
                return true;

            visited.insert(head);
            head = head->next;
        }

        return false;
    }
};