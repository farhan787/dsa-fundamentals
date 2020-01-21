// This program add two link lists and returns a new sum link list

// Input first line takes length of two lists
// second and third line takes len_1 and len_2 elements of lists l1 and l2

// Input:
// 4 3
// 2 4 3 8

// Output:
// 5 6 4

// List view
// 2 -> 4 -> 3 -> 8
// 5 -> 6 -> 4
// 3 -> 0 -> 0 -> 2

#include <iostream>

using std::abs;
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

class Pair {
   public:
    int carry;
    int data;
    Pair() {
        carry = data = 0;
    }
};

class PartialSum {
   public:
    int carry;
    Node* list;
    PartialSum() {
        carry = 0;
        list = NULL;
    }
};

void readInput(Node*& l1, Node*& l2);
int getLen(Node* head);
Node* insertAtTail(Node* head, int data);
Node* insertAtHead(Node* head, int data);
void printList(Node* head);

Pair calcValues(int sum, int carry) {
    Pair p;

    sum += carry;
    carry = 0;

    if (sum > 9) {
        int temp = sum % 10;
        p.data = temp;
        p.carry = sum / 10;
    } else {
        p.data = sum;
        p.carry = carry;
    }

    return p;
}

Node* addUnfinishedList(Node* head, Node* head_pointer, Node* sumList, int& carry) {
    // add the longer lists remaining nodes to the sum list
    if (head == head_pointer) {
        return sumList;
    }

    sumList = addUnfinishedList(head->next, head_pointer, sumList, carry);

    Pair values = calcValues(head->data, carry);
    int sum = values.data;
    carry = values.carry;

    sumList = insertAtHead(sumList, sum);
    return sumList;
}

Node* padList(Node* pointer, int lenDiff) {
    // move list pointer to lenDiff len ahead
    for (int i = 1; i <= lenDiff; i++) {
        pointer = pointer->next;
    }
    return pointer;
}

PartialSum addListsHelper(Node* l1_pointer, Node* l2_pointer) {
    PartialSum partialSum;
    if (l1_pointer == NULL && l2_pointer == NULL) return partialSum;

    partialSum = addListsHelper(l1_pointer->next, l2_pointer->next);
    Node* head = partialSum.list;
    int carry = partialSum.carry;

    int sum = l1_pointer->data + l2_pointer->data;
    Pair values = calcValues(sum, carry);
    sum = values.data;
    carry = values.carry;

    head = insertAtHead(head, sum);
    partialSum.list = head;
    partialSum.carry = carry;

    return partialSum;
}

Node* addLists(Node* l1, Node* l2) {
    int len_1 = getLen(l1);
    int len_2 = getLen(l2);

    int lenDiff = abs(len_1 - len_2);

    Node* l1_pointer = l1;
    Node* l2_pointer = l2;
    if (len_1 > len_2) {
        l1_pointer = padList(l1_pointer, lenDiff);
    } else if (len_1 < len_2) {
        l2_pointer = padList(l2_pointer, lenDiff);
    }

    PartialSum partialSum = addListsHelper(l1_pointer, l2_pointer);
    Node* sumList = partialSum.list;
    int carry = partialSum.carry;

    if (l1_pointer != l1) sumList = addUnfinishedList(l1, l1_pointer, sumList, carry);
    if (l2_pointer != l2) sumList = addUnfinishedList(l2, l2_pointer, sumList, carry);

    if (carry) sumList = insertAtHead(sumList, carry);

    return sumList;
}

int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    readInput(l1, l2);

    Node* sumList = addLists(l1, l2);
    printList(sumList);
}

int getLen(Node* head) {
    int len = 0;
    while (head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}

void printList(Node* head) {
    if (head == NULL) {
        return;
    }

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertAtHead(Node* head, int data) {
    Node* n = new Node(data);
    if (head == NULL) {
        head = n;
        return head;
    }

    n->next = head;
    head = n;
    return head;
}

Node* insertAtTail(Node* head, int data) {
    Node* n = new Node(data);
    if (head == NULL) {
        head = n;
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    return head;
}

void readInput(Node*& l1, Node*& l2) {
    int len_1, len_2;
    cin >> len_1 >> len_2;

    for (int i = 0; i < len_1; i++) {
        int data;
        cin >> data;

        l1 = insertAtTail(l1, data);
    }

    for (int i = 0; i < len_2; i++) {
        int data;
        cin >> data;

        l2 = insertAtTail(l2, data);
    }
}
