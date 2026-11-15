// PRN: 202501100019
// Key: S = 19, scenario = cold-drink flavours, hash = mid-square,
//      collision = separate chaining, m = 31
#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

const int M = 31;
list<int> table_[M];   // will be used for chaining in the next stage
int simpleTable[M];    // first attempt: one key per slot, -1 means empty

// mid-square: square the key, take middle 2 digits of the 4-digit square, then mod M
int hashFunc(int key) {
    int sq = key * key;
    int mid = (sq / 10) % 100;
    return mid % M;
}

// first attempt: no collision handling, the new key simply goes in the slot
void insertSimple(int key) {
    int idx = hashFunc(key);
    if (simpleTable[idx] != -1)
        cout << "Overwrite at index " << idx << ": " << simpleTable[idx]
             << " replaced by " << key << "\n";
    simpleTable[idx] = key;
}

int main() {
    for (int i = 0; i < M; i++) simpleTable[i] = -1;

    int S = 19;
    for (int i = 0; i < 20; i++) {
        int v = (S + 13 * i) % 100;
        insertSimple(v);
    }

    int stored = 0;
    for (int i = 0; i < M; i++) {
        if (simpleTable[i] != -1) {
            cout << setw(2) << i << " : " << simpleTable[i] << "\n";
            stored++;
        }
    }
    cout << "Keys inserted: 20, keys stored: " << stored << "\n";
    return 0;
}