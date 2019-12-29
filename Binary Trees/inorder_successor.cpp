#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Given a BST with parent pointers find the inorder successor of a given node
// 			20
// 		   /  \
//        9   25
// 	    /  \  
// 	   5   12
// 	      /  \
// 	    11   14

// inorderSuccessor(9) -> 11
// inorderSuccessor(14) -> 20

// Input:
// 7
// 20 9 25 5 12 11 14

class Node {
   public:
    int data;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = NULL;
    }
};

Node* insertNode(Node* root, int data) {
    // insert node in bst
    Node* node = new Node(data);
    if (root == NULL) {
        root = node;
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
        root->left->parent = root;
    } else {
        root->right = insertNode(root->right, data);
        root->right->parent = root;
    }

    return root;
}

Node* buildBST() {
    int n;
    cin >> n;
    Node* root = NULL;
    while (n--) {
        int data;
        cin >> data;
        root = insertNode(root, data);
    }
    return root;
}

Node* findMinKey(Node* inputNode) {
    while (inputNode->left != NULL) {
        inputNode = inputNode->left;
    }
    return inputNode;
}

Node* getInorderSuccessor(Node* inputNode) {
    Node* key = inputNode;
    // if key has right child then inorder successor would be the minimum key value in right subtree
    if (key->right) {
        return findMinKey(key->right);
    }

    // if key has no right child then it would be parent of parent ancestor which is left child of
    // a parent node and if there is no such parent then there is no inorder successor
    else {
        while (key->parent != NULL && key->parent->left != key) {
            key = key->parent;
        }
        return key->parent;
    }
}

int main() {
    Node* root = buildBST();
    Node* inorderSuccessor = getInorderSuccessor(root->left->right->right);
    if (inorderSuccessor != NULL) {
        cout << inorderSuccessor->data << endl;
    } else {
        cout << "Doesn't exist" << endl;
    }
}
