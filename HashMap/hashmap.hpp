#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <math.h>

#include <vector>
using namespace std;

// using prime number helps to uniformly distribute entries in our hash map
const int PRIME_NUMBER = 11;
const float LOAD_FACTOR_THRESHOLD = 0.70;

template <typename value_type>
class Node {
   public:
    string key;
    value_type value;

    Node<value_type>* next;

    Node(string key, value_type value) {
        this->key = key;
        this->value = value;
    }

    ~Node() {
        // to avoid memory leaks
        if (next != NULL) {
            delete next;
        }
    }
};

template <typename value_type>
class HashMap {
   private:
    int total_size;
    int curr_size;

    Node<value_type>** buckets;

    long long getHashValue(string key) {
        long long hash_value = 0;
        for (int i = 0; i < (int)key.length(); i++) {
            hash_value += key[i] * pow(PRIME_NUMBER, i);
        }
        return hash_value;
    }

    int getHashIndex(string key) {
        long long hash_value = getHashValue(key);
        int hash_index = hash_value % total_size;
        return hash_index;
    }

    void rehash() {
        curr_size = 0;

        int old_total_size = total_size;

        // total_size should be nextPrimeNumber to have uniform distribution of keys
        // total_size = getNextPrimeNumber(total_size);
        total_size = 2 * old_total_size + 1;

        Node<value_type>** old_buckets = buckets;

        buckets = new Node<value_type>*[total_size];
        for (int i = 0; i < total_size; i++) {
            buckets[i] = NULL;
        }

        for (int i = 0; i < old_total_size; i++) {
            Node<value_type>* curr_node = old_buckets[i];
            while (curr_node != NULL) {
                string key = curr_node->key;
                value_type value = curr_node->value;

                this->insert(key, value);
                curr_node = curr_node->next;
            }

            if (old_buckets[i]) {
                // for deleting link list at every index
                delete old_buckets[i];
            }
        }
        delete[] old_buckets;
    }

   public:
    HashMap(int default_size = PRIME_NUMBER) {
        curr_size = 0;
        total_size = default_size;

        buckets = new Node<value_type>*[total_size];
        for (int i = 0; i < total_size; i++) {
            buckets[i] = NULL;
        }
    }

    void insert(string key, value_type value) {
        int hash_index = getHashIndex(key);

        Node<value_type>* new_node = new Node<value_type>(key, value);
        new_node->next = buckets[hash_index];
        buckets[hash_index] = new_node;
        ++curr_size;

        float load_factor = curr_size / (float)(total_size);
        if (load_factor > LOAD_FACTOR_THRESHOLD) {
            cout << "for " << key << " load factor is " << load_factor << ", rehashing..." << endl;
            rehash();
        }
    }

    Node<value_type>* search(string key) {
        int hash_index = getHashIndex(key);
        Node<value_type>* curr_node = buckets[hash_index];

        while (curr_node != NULL) {
            if (curr_node->key == key) {
                return curr_node;
            }
            curr_node = curr_node->next;
        }
        return NULL;
    }

    void erase(string key) {
        int hash_index = getHashIndex(key);

        Node<value_type>* curr_node = buckets[hash_index];
        Node<value_type>* prev_node = NULL;

        while (curr_node != NULL) {
            if (curr_node->key == key) {
                if (curr_node == buckets[hash_index]) {
                    // curr_node is head of the link list
                    buckets[hash_index] = curr_node->next;
                    delete curr_node;
                    return;
                }

                prev_node = curr_node->next;
                delete curr_node;
                return;
            }
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }

    int count(string key) {
        int hash_index = getHashIndex(key);
        Node<value_type>* curr_node = buckets[hash_index];
        while (curr_node != NULL) {
            if (curr_node->key == key) {
                return 1;
            }
            curr_node = curr_node->next;
        }
        return 0;
    }

    // operator overloading to support map[key] feature
    value_type& operator[](string key) {
        Node<value_type>* node = this->search(key);
        if (node == NULL) {
            value_type garbage;
            this->insert(key, garbage);

            node = this->search(key);
        }
        return node->value;
    }

    void print() {
        // just to print our map, to see distribution of keys
        for (int i = 0; i < total_size; i++) {
            cout << "bucket " << i << " -> ";

            Node<value_type>* curr_node = buckets[i];
            while (curr_node != NULL) {
                cout << curr_node->key << ", " << curr_node->value << " | ";
                curr_node = curr_node->next;
            }
            cout << endl;
        }
    }
};

#endif
