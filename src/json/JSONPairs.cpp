#include "JSON.h"

JSON::JSONPairs::JSONPairs() : _size(0) {

};

JSON::JSONPairs::~JSONPairs() {
    delete[] _indexedPairs;
};

void JSON::JSONPairs::newPair(const JSON::JSONPair<int>& pair) {
    IndexedPair* newIndexedPairs = new IndexedPair[_size + 1];
    for (int i = 0; i < _size; i++) {
        newIndexedPairs[i] = _indexedPairs[i];
    }
    newIndexedPairs[_size] = IndexedPair(_size, pair);
    delete[] _indexedPairs;
    _indexedPairs = newIndexedPairs;
};

JSON::JSONPair<int>& JSON::JSONPairs::operator[](const int& index) {
    return _indexedPairs[index]._intPair;
};

JSON::JSONPairs::IndexedPair::IndexedPair(const int& index, const JSON::JSONPair<int>& pair) : _index(index) {
    _intPair = pair;
};