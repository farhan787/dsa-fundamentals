#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void printlevelOrderBFS(Node* root) {
    // O(N)
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* f = q.front();

        if (f == NULL) {
            cout << endl;
            q.pop();

            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << f->data << " ";
            q.pop();

            if (f->left) {
                q.push(f->left);
            }

            if (f->right) {
                q.push(f->right);
            }
        }
    }
}

Node* insertNode(Node* root, int data) {
    Node* n = new Node(data);

    if (root == NULL) {
        root = n;
        return root;
    }

    // Tree: 5
    //      / \
              10
    // New node: 10

    if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else {
        root->left = insertNode(root->left, data);
    }

    return root;
}

Node* buildBST() {
    // read till -1 is encountered
    int data;
    cin >> data;

    Node* root = NULL;
    while (data != -1) {
        root = insertNode(root, data);
        cin >> data;
    }

    return root;
}

Node* search(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (root->data == data) {
        return root;
    }

    if (root->data < data) {
        return search(root->right, data);
    }

    return search(root->left, data);
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        // found the node to be deleted

        // delete node having 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // delete node having 1 child
        if (root->left != NULL && root->right == NULL) {
            Node* child = root->left;
            delete root;
            return child;
        }
        if (root->left == NULL && root->right != NULL) {
            Node* child = root->right;
            delete root;
            return child;
        }

        // delete node having 2 children
        if (root->left != NULL && root->right != NULL) {
            Node* replace = root->right;
            // find the inorder successor from right subtree
            while (replace->left != NULL) {
                replace = replace->left;
            }
            root->data = replace->data;
            // delete the replacement node recursively
            root->right = deleteNode(root->right, replace->data);

            return root;
        }

    } else if (root->data < data) {
        root->right = deleteNode(root->right, data);
    } else {
        root->left = deleteNode(root->left, data);
    }

    return root;
}

class triplet {
   public:
    int maxV, minV;
    bool isBST;
};

triplet checkBST_BU(Node* root) {
    // Bottom UP approach
    triplet t;
    if (root == NULL) {
        t.maxV = INT_MIN;
        t.minV = INT_MAX;
        t.isBST = true;
        return t;
    }

    triplet leftT = checkBST_BU(root->left);
    triplet rightT = checkBST_BU(root->right);

    if (root->data > rightT.maxV) {
        t.maxV = root->data;
    }

    if (root->data < leftT.minV) {
        t.minV = root->data;
    }

    if (root->data >= leftT.maxV && root->data < rightT.minV && leftT.isBST && rightT.isBST) {
        t.isBST = true;
    } else {
        t.isBST = false;
    }

    return t;
}

bool checkBST_TD(Node* root, int maxV = INT_MAX, int minV = INT_MIN) {
    // Top DOWN approach
    if (root == NULL) {
        return true;
    }

    if (root->data >= minV && root->data <= maxV && checkBST_TD(root->left, root->data, minV) && checkBST_TD(root->right, maxV, root->data)) {
        return true;
    }

    return false;
}

bool inorderTraversal(Node* root, Node*& prevNode) {
    if (root == NULL) {
        return true;
    }

    if (!inorderTraversal(root->left, prevNode)) {
        return false;
    }

    if (prevNode != NULL && prevNode->data > root->data) {
        return false;
    }
    prevNode = root;

    if (!inorderTraversal(root->right, prevNode)) {
        return false;
    }

    return true;
}

bool isBST(Node* root) {
    // using inorder traversal
    // inorder traversal of BST is always in ascending order
    Node* prevNode = NULL;
    return inorderTraversal(root, prevNode);
}

int main() {
    Node* root = buildBST();
    // printlevelOrderBFS(root);
    // cout << endl;

    Node* d = deleteNode(root, 9);
    printlevelOrderBFS(root);
    cout << endl;

    checkBST_BU(root).isBST ? cout << "Yes, it is a BST" : cout << "No, it is not a BST";
    cout << endl;

    checkBST_TD(root) ? cout << "Yes, it is a BST" : cout << "No, it is not a BST";
    cout << endl;

    isBST(root) ? cout << "Yes, it is a BST" : cout << "No, it is not a BST";
    cout << endl;

    // Node* node = search(root, 9);
    // if (node != NULL) {
    //     cout << node << endl;
    //     cout << node->data << endl;
    // } else {
    //     cout << "Node does not exist" << endl;
    // }
}
