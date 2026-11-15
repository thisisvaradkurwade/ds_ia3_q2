// PRN: 202501100019
// Key: S = 19, scenario = cold-drink flavours, hash = mid-square,
//      collision = separate chaining, m = 31
#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

const int M = 31;
const int N = 20;      // number of keys
list<int> table_[M];   // each bucket is a chain (linked list) of keys

// mid-square: square the key, take middle 2 digits of the 4-digit square, then mod M
int hashFunc(int key) {
    int sq = key * key;
    int mid = (sq / 10) % 100;
    return mid % M;
}

// dataset from the formula v[i] = (S + 13*i) mod 100, i = 0..N-1
void generateDataset(int S, int v[]) {
    for (int i = 0; i < N; i++)
        v[i] = (S + 13 * i) % 100;
}

// separate chaining: if the bucket is not empty, the key is added at the end of its chain
void insertKey(int key) {
    int idx = hashFunc(key);
    if (!table_[idx].empty())
        cout << "Collision at index " << idx << " for key " << key << "\n";
    table_[idx].push_back(key);
}

// print every bucket with its chain
void display() {
    for (int i = 0; i < M; i++) {
        cout << setw(2) << i << " : ";
        if (table_[i].empty()) cout << "-";
        for (int x : table_[i]) cout << x << " -> ";
        cout << "\n";
    }
}

int main() {
    int S = 19;
    int v[N];
    generateDataset(S, v);

    cout << "Dataset: ";
    for (int i = 0; i < N; i++) cout << v[i] << " ";
    cout << "\n\n";

    for (int i = 0; i < N; i++) {
        cout << "Insert " << v[i] << " -> index " << hashFunc(v[i]) << "\n";
        insertKey(v[i]);
    }

    cout << "\nFinal table:\n";
    display();
    return 0;
}