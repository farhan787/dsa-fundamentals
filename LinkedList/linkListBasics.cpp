#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Node {
   public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    if (head == NULL) {
        cout << "No nodes to print in the link list" << endl;
        return;
    }

    while (head != NULL) {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << endl;
}

int length(Node* head) {
    int len = 0;
    while (head != NULL) {
        head = head->next;
        len++;
    }

    return len;
}

void insertAtHead(Node*& head, int data) {
    Node* n = new Node(data);
    n->next = head;
    head = n;
}

void insertAtTail(Node*& head, int data) {
    Node* temp = head;
    Node* n = new Node(data);

    while (temp->next != NULL) {
        temp = temp->next;
    }

    n->next = NULL;
    temp->next = n;
}

void insertAtMiddle(Node*& head, int data, int position) {
    if (position < 1) {
        cout << "Not a valid position\n";
        return;
    }

    if (head == NULL || position == 1) {
        insertAtHead(head, data);
        return;
    }

    if (position > length(head)) {
        insertAtTail(head, data);
        return;
    }

    Node* n = new Node(data);

    Node* temp = head;
    for (int jump = 1; jump <= position - 2; jump++) {
        temp = temp->next;
    }

    n->next = temp->next;
    temp->next = n;
}

int findMidPoint(Node*& head) {
    Node* slowPointer = head;
    Node* fastPointer = head;

    while (fastPointer->next != NULL && (fastPointer->next)->next != NULL) {
        slowPointer = slowPointer->next;
        fastPointer = (fastPointer->next)->next;
    }

    return slowPointer->data;
}

void deleteAtHead(Node*& head) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(Node*& head) {
    if (head == NULL) {
        return;
    }

    Node* tempPrevious = head;
    Node* temp = head->next;

    while (temp->next != NULL) {
        temp = temp->next;
        tempPrevious = tempPrevious->next;
    }

    tempPrevious->next = NULL;
    delete temp;
}

void deleteAtMiddle(Node*& head, int position) {
    if (head == NULL) {
        cout << "No nodes to delete in the link list" << endl;
        return;
    }

    if (position > length(head)) {
        deleteAtTail(head);
        return;
    }

    Node* temp = head;
    for (int jump = 1; jump <= position - 2; jump++) {
        temp = temp->next;
    }

    Node* nodeToBeDeleted = temp->next;
    temp->next = nodeToBeDeleted->next;

    delete nodeToBeDeleted;
}

int iterativeSearch(Node* head, int element) {
    if (head == NULL) {
        cout << "No nodes to search element" << endl;
        return -1;
    }

    int position = 0;
    while (head != NULL) {
        position++;
        if (head->data == element) {
            return position;
        }

        head = head->next;
    }

    return -1;
}

int recursiveSearch(Node*& head, int element, int count) {
    if (head == NULL) {
        return -1;
    }

    Node* temp = head;

    // Base Case
    if (temp->next == NULL && temp->data != element) {
        return -1;
    }

    if (temp->data == element) {
        return ++count;
    }

    return recursiveSearch(head->next, element, count + 1);
}

int main() {
    Node* head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 1);

    insertAtMiddle(head, 0, 1);
    insertAtMiddle(head, 2, 3);
    insertAtMiddle(head, 90, 30);

    print(head);
    cout << endl;

    int midPoint = findMidPoint(head);
    cout << "Mid point: " << midPoint << endl;
    cout << endl;

    deleteAtHead(head);
    print(head);

    deleteAtTail(head);
    print(head);

    deleteAtMiddle(head, 3);
    print(head);

    deleteAtMiddle(head, 30);
    print(head);

    int position1 = iterativeSearch(head, 4);
    cout << "4 element position: " << position1 << endl;

    int position2 = recursiveSearch(head, 4, 0);
    cout << "4 element position: " << position2 << endl;
}
