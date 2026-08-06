class Solution {
public:

    Node* dfs(Node* head){

        Node* curr = head;
        Node* last = head;

        while(curr){

            Node* nxt = curr->next;

            if(curr->child){

                Node* child = curr->child;
                Node* childTail = dfs(child);

                curr->next = child;
                child->prev = curr;
                curr->child = NULL;

                childTail->next = nxt;

                if(nxt)
                    nxt->prev = childTail;

                last = childTail;
            }
            else{
                last = curr;
            }

            curr = nxt;
        }

        return last;
    }

    Node* flatten(Node* head) {

        if(!head)
            return NULL;

        dfs(head);

        return head;
    }
};