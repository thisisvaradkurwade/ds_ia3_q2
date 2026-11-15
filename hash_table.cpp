// PRN: 202501100019
// Key: S = 19, scenario = cold-drink flavours, hash = mid-square,
//      collision = separate chaining, m = 31
#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

const int M = 31;
list<int> table_[M];   // each bucket is a chain (linked list) of keys

// mid-square: square the key, take middle 2 digits of the 4-digit square, then mod M
int hashFunc(int key) {
    int sq = key * key;
    int mid = (sq / 10) % 100;
    return mid % M;
}

// separate chaining: if the bucket is not empty, the key is added at the end of its chain
void insertKey(int key) {
    int idx = hashFunc(key);
    if (!table_[idx].empty())
        cout << "Collision at index " << idx << " for key " << key << "\n";
    table_[idx].push_back(key);
}

int main() {
    int S = 19;
    for (int i = 0; i < 20; i++) {
        int v = (S + 13 * i) % 100;
        insertKey(v);
    }

    int stored = 0;
    for (int i = 0; i < M; i++) stored += table_[i].size();
    cout << "Keys inserted: 20, keys stored: " << stored << "\n";
    return 0;
}