#include <iostream>
#include <vector>

#include "hashmap.hpp"

using namespace std;

class Fruit {
   public:
    string name;
    int price;

    Fruit(string name, int price) {
        this->name = name;
        this->price = price;
    }
};

int main() {
    HashMap<int> price;

    vector<Fruit> fruits = {
        Fruit("kiwi", 160),
        Fruit("apple", 100),
        Fruit("custard apple", 130),
        Fruit("banana", 40),
    };

    vector<string> fruit_names = {"apple", "orange", "banana", "pineapple", "custard apple", "melon"};

    for (Fruit fruit : fruits) {
        price.insert(fruit.name, fruit.price);
    }

    for (string fruit_name : fruit_names) {
        if (price.count(fruit_name)) {
            cout << "Price of " << fruit_name << " is " << price[fruit_name] << endl;
        } else {
            cout << fruit_name << " is not present in our hash map" << endl;
        }
    }

    // garbage value as we didn't intentionally insert orange in our map
    // but as we've checked its price, so now it's present with value as garbage value
    cout << "Price of orange is " << price["orange"] << endl;
}
