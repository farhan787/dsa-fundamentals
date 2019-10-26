#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::vector;

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

        // block index 0
        v.push_back(-1);

        this->isMinHeap = isMinHeap;
    }

    void push(int data) {
        // insert at last
        v.push_back(data);

        // move it to correct position
        int index = v.size() - 1;
        int parent = index / 2;

        while (index > 1 && isViolating(v[parent], v[index])) {
            swap(v[parent], v[index]);

            index = parent;
            parent = parent / 2;
        }
    }

    void pop() {
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
    Heap h;
    h.push(1);
    h.push(20);
    h.push(2);
    h.push(100);
    h.push(40);
    h.push(3);

    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }

    cout << endl;
}

