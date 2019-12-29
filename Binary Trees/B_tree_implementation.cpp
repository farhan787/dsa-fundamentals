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

// preOrder
void printPreOrder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node* root) {
    if (root == NULL) return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(Node* root) {
    if (root == NULL) return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSubTreeHt = height(root->left);
    int rightSubTreeHt = height(root->right);

    int currentHt = max(leftSubTreeHt, rightSubTreeHt) + 1;
    return currentHt;
}

void printKthLevel(Node* root, int level) {
    if (root == NULL) return;

    if (level == 1) {
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, level - 1);
    printKthLevel(root->right, level - 1);
}

void printLevelOrder(Node* root) {
    int ht = height(root);

    for (int level = 1; level <= ht; level++) {
        printKthLevel(root, level);
        cout << endl;
    }
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

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);

    int totalNodes = leftNodes + rightNodes + 1;
    return totalNodes;
}

int sumOfNodes(Node* root) {
    if (root == NULL) return 0;

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    int totalSum = leftSum + rightSum + root->data;
    return totalSum;
}

int calcDiameter(Node* root) {
    // Preorder traversal

    if (root == NULL) return 0;

    // O(N^2)
    int leftHt = height(root->left);
    int rightHt = height(root->right);

    // if diameter passes through the root
    int d1 = leftHt + rightHt;

    // if diameter does not pass through the root
    // it's inside the left subtree
    int d2 = calcDiameter(root->left);

    // it's inside the right subtree
    int d3 = calcDiameter(root->right);

    return max(d1, max(d2, d3));
}

class Pair {
   public:
    int height;
    int diameter;
};

Pair fastDiameter(Node* root) {
    // Postorder Traversal
    // BottomUP

    Pair p;
    if (root == NULL) {
        p.diameter = p.height = 0;
        return p;
    }

    Pair leftP = fastDiameter(root->left);
    Pair rightP = fastDiameter(root->right);

    p.height = max(leftP.height, rightP.height) + 1;
    p.diameter = max(leftP.height + rightP.height, max(leftP.diameter, rightP.diameter));

    return p;
}

int replaceWithSum(Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }

    int leftSum = replaceWithSum(root->left);
    int rightSum = replaceWithSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;

    return temp + leftSum + rightSum;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    // // printPreOrder(root);
    // // cout << endl;

    // // printInOrder(root);
    // // cout << endl;

    // // printPostOrder(root);
    // // cout << endl;

    // printLevelOrder(root);
    // cout << endl;

    // printlevelOrderBFS(root);
    // cout << endl;

    // cout << countNodes(root) << endl;
    // cout << sumOfNodes(root) << endl;

    // cout << calcDiameter(root) << endl;
    // cout << fastDiameter(root).diameter << endl;

    printlevelOrderBFS(root);
    cout << endl;

    replaceWithSum(root);

    printlevelOrderBFS(root);
    cout << endl;
}

