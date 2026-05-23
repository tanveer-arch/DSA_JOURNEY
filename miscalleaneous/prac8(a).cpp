#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
    int BUCKET;
    vector<list<int>> table;

public:
    HashTable(int size) {
        BUCKET = size;
        table.resize(BUCKET);
    }

    int hashFunction(int key) {
        return key % BUCKET;
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i << " --> ";
            for (auto x : table[i])
                cout << x << " -> ";
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable h(10);
    int keys[20] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16,
                    5, 55, 22, 45, 99, 1, 67, 33, 78, 43};

    for (int i = 0; i < 20; i++)
        h.insertItem(keys[i]);

    cout << "\nHash Table (Separate Chaining):\n";
    h.displayHash();
    return 0;
}
