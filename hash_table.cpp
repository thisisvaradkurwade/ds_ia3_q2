// PRN: 202501100019
// Key: S = 19, scenario = cold-drink flavours, hash = mid-square,
//      collision = separate chaining, m = 31
#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

const int M = 31;
list<int> table_[M];

// mid-square: square the key, take middle 2 digits of the 4-digit square, then mod M
int hashFunc(int key) {
    int sq = key * key;
    int mid = (sq / 10) % 100;
    return mid % M;
}

int main() {
    cout << "hash(19) = " << hashFunc(19) << "\n";
    cout << "hash(32) = " << hashFunc(32) << "\n";
    cout << "hash(45) = " << hashFunc(45) << "\n";
    cout << "hash(1) = " << hashFunc(1) << "\n";
    return 0;
}