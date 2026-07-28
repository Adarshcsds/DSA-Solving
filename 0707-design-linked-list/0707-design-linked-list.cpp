class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;

    // Constructor
    MyLinkedList() {
        head = NULL;
    }

    // Get value at index
    int get(int index) {
        Node* temp = head;
        int i = 0;

        while (temp != NULL) {
            if (i == index)
                return temp->data;

            temp = temp->next;
            i++;
        }

        return -1;
    }

    // Insert at beginning
    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at given index
    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        // Invalid index
        if (temp == NULL)
            return;

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete node at given index
    void deleteAtIndex(int index) {

        if (head == NULL)
            return;

        // Delete head
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        // Invalid index
        if (temp == NULL || temp->next == NULL)
            return;

        Node* delNode = temp->next;

        temp->next = delNode->next;

        delete delNode;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index, val);
 * obj->deleteAtIndex(index);
 */