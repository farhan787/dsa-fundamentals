// Merge k sorted arrays

// INPUT format
// 3
// 5
// 2 3 12 15 20
// 2
// 0 24
// 4
// 7 8 90 100

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;

class comparePair {
   public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> v, int k) {
    vector<int> mergedVector;

    // Heap of pairs -> (element, arrayId)
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparePair> minHeap;

    // vector to store the pointers of k arrays to point element
    vector<int> pointerVector;
    pointerVector.reserve(k);
    for (int i = 0; i < k; i++) {
        // initially all pointers will point to index 0
        pointerVector.push_back(0);
    }

    // put k first elements of arrays in minHeap
    for (int i = 0; i < k; i++) {
        // pair -> (element, arrayId)
        int pointer = pointerVector[i];
        int element = v[i][pointer];
        int arrayId = i;

        pair<int, int> p(element, arrayId);
        minHeap.push(p);
    }

    while (minHeap.top().first != INT_MAX) {
        int element = minHeap.top().first;
        int arrayId = minHeap.top().second;

        // put it in the final merged vector
        mergedVector.push_back(element);

        // remove the pair
        minHeap.pop();

        // increment the pointer to next element of respective array
        pointerVector[arrayId]++;

        // put the next element from same array in the heap
        int pointer = pointerVector[arrayId];

        // check if the array is complete
        if (pointer >= v[arrayId].size()) {
            pair<int, int> p(INT_MAX, arrayId);
            minHeap.push(p);
            continue;
        }

        int nextElement = v[arrayId][pointer];
        pair<int, int> p(nextElement, arrayId);
        minHeap.push(p);
    }

    return mergedVector;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int>> v;

    // store the k sorted arrays
    for (int i = 0; i < k; i++) {
        vector<int> innerVector;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int element;
            cin >> element;

            innerVector.push_back(element);
        }

        v.push_back(innerVector);
    }

    vector<int> mergedArray = mergeKSortedArrays(v, k);

    for (auto x : mergedArray) {
        cout << x << " ";
    }

    cout << endl;
}
