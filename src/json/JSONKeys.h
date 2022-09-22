#pragma once
#include "JSON.h"

class JSON::JSONKeys {
public:
    JSONKeys();
    ~JSONKeys();

    bool isValidKey(const std::string& key) const;
    bool isValidKey(const JSONKey& key) const;

    void addKey(const std::string& key);
    void addKey(const JSON::JSONKey& key);

    friend std::ostream& operator<<(std::ostream& os, const JSONKeys& keys);

    struct Iterator;

    Iterator begin();
    Iterator end();

private:
    int _size;
    JSON::JSONKey* _keys;

    void copyKeys(const JSON::JSONKey* oldKeys, const int& size, JSON::JSONKey* newKeys) const;
};

// All taken from: https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
struct JSON::JSONKeys::Iterator {
public:
    Iterator(JSON::JSONKey* ptr);

    JSON::JSONKey& operator*();
    JSON::JSONKey* operator->();

    Iterator& operator++();

    Iterator operator++(int);

    friend bool operator==(const Iterator& a, const Iterator& b);
    friend bool operator!=(const Iterator& a, const Iterator& b);

private:
    JSON::JSONKey* _ptr;
};