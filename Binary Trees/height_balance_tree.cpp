#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::queue;

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

Node* buildTree(Node* root) {
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

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

class Pair {
   public:
    int height;
    bool isBalanced;
};

Pair isHeightBalancedTree(Node* root) {
    Pair p;
    if (root == NULL) {
        p.height = 0;
        p.isBalanced = true;
        return p;
    }

    Pair leftP = isHeightBalancedTree(root->left);
    Pair rightP = isHeightBalancedTree(root->right);

    p.height = max(leftP.height, rightP.height) + 1;

    int htDiff = abs(leftP.height - rightP.height);
    if (htDiff <= 1 && leftP.isBalanced && rightP.isBalanced) {
        p.isBalanced = true;
    } else {
        p.isBalanced = false;
    }

    return p;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    printlevelOrderBFS(root);
    cout << endl;

    isHeightBalancedTree(root).isBalanced ? cout << "Balanced" : cout << "Not balanced";
    cout << endl;
}

