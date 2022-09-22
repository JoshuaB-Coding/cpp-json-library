#include "JSON.h"

JSON::JSONKeys::JSONKeys() : _size(0) {

};

JSON::JSONKeys::~JSONKeys() {
    delete[] _keys;
};

JSON::JSONKeys::Iterator JSON::JSONKeys::begin() {
    return Iterator(&_keys[0]);
};

JSON::JSONKeys::Iterator JSON::JSONKeys::end() {
    return Iterator(&_keys[_size]);
};

bool JSON::JSONKeys::isValidKey(const std::string& key) const {
    JSONKey queryKey = JSONKey(key);
    return isValidKey(queryKey);
};

bool JSON::JSONKeys::isValidKey(const JSON::JSONKey& key) const {
    for (int i = 0; i < _size; i++) {
        if (key == _keys[i]) return false;
    }
    return true;
};

void JSON::JSONKeys::addKey(const std::string& key) {
    JSONKey newKey = JSONKey(key);
    addKey(newKey);
};

void JSON::JSONKeys::addKey(const JSON::JSONKey& key) {
    JSON::JSONKey* newKeys = new JSON::JSONKey[_size + 1];
    copyKeys(_keys, _size, newKeys);
    newKeys[_size] = key;
    delete[] _keys;
    _keys = newKeys;
    _size++;
};

void JSON::JSONKeys::copyKeys(const JSON::JSONKey* oldKeys, const int& size, JSON::JSONKey* newKeys) const {
    for (int i = 0; i < size; i++) {
        newKeys[i] = oldKeys[i];
    }
};

std::ostream& JSON::operator<<(std::ostream& os, const JSON::JSONKeys& keys) {
    if (keys._size == 0) {
        os << "No keys present";
        return os;
    }
    os << "List of keys: [";
    for (int i = 0; i < keys._size; i++) {
        os << "\n    " << keys._keys[i];
    }
    os << "\n]";
    return os;
};

JSON::JSONKeys::Iterator::Iterator(JSON::JSONKey* ptr) : _ptr(ptr) {

};

JSON::JSONKey& JSON::JSONKeys::Iterator::operator*() {
    return *_ptr;
};

JSON::JSONKey* JSON::JSONKeys::Iterator::operator->() {
    return _ptr;
};

JSON::JSONKeys::Iterator& JSON::JSONKeys::Iterator::operator++() {
    _ptr++;
    return *this;
};

JSON::JSONKeys::Iterator JSON::JSONKeys::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
};

bool JSON::operator==(const JSON::JSONKeys::Iterator& a, const JSON::JSONKeys::Iterator& b) {
    return a._ptr == b._ptr;
};

bool JSON::operator!=(const JSON::JSONKeys::Iterator& a, const JSON::JSONKeys::Iterator& b) {
return a._ptr != b._ptr;
};