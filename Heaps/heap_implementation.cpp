#include <iostream>
#include <vector>

using namespace std;

class Heap {
   private:
    vector<int> v;
    bool isMinHeap;

    bool isViolating(int parent, int child) {
        return isMinHeap ? parent > child : parent < child;
    }

    void heapify(int index) {
        int leftChild = 2 * index;
        int rightChild = leftChild + 1;

        // Assume that current index has minimum or maximum element
        int minMaxIndex = index;

        if (leftChild < v.size() && isViolating(v[minMaxIndex], v[leftChild])) {
            minMaxIndex = leftChild;
        }

        if (rightChild < v.size() && isViolating(v[minMaxIndex], v[rightChild])) {
            minMaxIndex = rightChild;
        }

        if (minMaxIndex != index) {
            swap(v[index], v[minMaxIndex]);

            // Recursively go down from minMaxIndex
            heapify(minMaxIndex);
        }
    }

   public:
    Heap(int defaultSize = 50, bool isMinHeap = true) {
        v.reserve(defaultSize);

        // block index 0, it'd help us to find the leftChild and rightChild of a node using Complete Binary Tree property
        v.push_back(-1);

        this->isMinHeap = isMinHeap;
    }

    void push(int data) {
        // HOW TO PUSH NEW ELEMENT IN HEAP
        // insert it to the end index and then move it to its correct position
        v.push_back(data);

        // moving it to its correct position
        int currIndex = v.size() - 1;
        int parentIndex = currIndex / 2;

        while (currIndex > 1 && isViolating(v[parentIndex], v[currIndex])) {
            swap(v[parentIndex], v[currIndex]);

            currIndex = parentIndex;
            parentIndex = parentIndex / 2;
        }
    }

    void pop() {
        // HOW TO POP TOP ELEMENT FROM HEAP
        // swap the first and last elements and the remove last element
        // after that maintain the heap order property for every node starting 1st node

        if (v.size() == 1) {
            return;
        }

        // swap the first and last elements
        int lastIndex = v.size() - 1;
        swap(v[1], v[lastIndex]);

        // remove the last element
        v.pop_back();

        // re-gain the heap order property from 1st element
        heapify(1);
    }

    int top() {
        return v[1];
    }

    bool empty() {
        return v.size() == 1;
    }
};

int main() {
    // Heap implementation
    const int heapSize = 50;
    bool isMinHeap = true;

    Heap h(heapSize, isMinHeap);
    for (int i = 0; i < 10; i++) {
        int num = rand() % 1000;
        h.push(num);
    }

    while (!h.empty()) {
        cout << h.top() << ", ";
        h.pop();
    }

    cout << endl;
}
