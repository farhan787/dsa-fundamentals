// Get k-nearest cars from the origin

#include <math.h>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::vector;

class Car {
   public:
    int x;
    int y;
    int id;

    Car(int id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    // distance from origin
    int distance() {
        return sqrt(x * x + y * y);
    }

    void printCar() {
        cout << "ID: " << id << ", x: " << x << " and y: " << y << endl;
    }
};

// Functors
class CompareCars {
   public:
    bool operator()(Car a, Car b) {
        // for min-heap
        return a.distance() > b.distance();
    }
};

class Heap {
   private:
    vector<Car> v;

    bool comparator(Car parent, Car child) {
        CompareCars cc;
        return cc(parent, child);
    }

    void heapify(int index) {
        int leftChild = 2 * index;
        int rightChild = leftChild + 1;

        int minMaxIndex = index;

        if (leftChild < v.size() && comparator(v[minMaxIndex], v[leftChild])) {
            minMaxIndex = leftChild;
        }

        if (rightChild < v.size() && comparator(v[minMaxIndex], v[rightChild])) {
            minMaxIndex = rightChild;
        }

        if (minMaxIndex != index) {
            swap(v[minMaxIndex], v[index]);
            heapify(minMaxIndex);
        }
    }

   public:
    Heap(int defaultSize = 50) {
        v.reserve(defaultSize);

        // block index 0
        Car blockingCar(0, 0, 0);
        v.push_back(blockingCar);
    }

    void push(Car a) {
        // insert the car at last
        v.push_back(a);

        // move this to its correct position
        int index = v.size() - 1;
        int parent = index / 2;

        while (index > 1 && comparator(v[parent], v[index])) {
            swap(v[parent], v[index]);

            index = parent;
            parent = parent / 2;
        }
    }

    void pop() {
        // swap first and last car
        int lastIndex = v.size() - 1;
        swap(v[1], v[lastIndex]);

        // remove the last car
        v.pop_back();

        // re-gain the heap order property
        heapify(1);
    }

    Car top() {
        return v[1];
    }

    bool empty() {
        return v.size() == 1;
    }
};

int main() {
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int y[10] = {2, 42, 12, -12, 4, 0, 39, 24, 34, 16};

    Heap q;
    int k = 5;

    for (int i = 0; i < 10; i++) {
        q.push(Car(i + 10, x[i], y[i]));
    }

    while (!q.empty()) {
        Car c = q.top();
        c.printCar();
        q.pop();
    }
}

