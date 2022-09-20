#include "JSON.h"

class JSON::JSONKeys {
public:
    JSONKeys();
    ~JSONKeys();

    struct Iterator;

    Iterator begin() { return Iterator(&keys[0]); }
    Iterator end() { return Iterator(&keys[_size]); }

    std::string* getKeys() const { return _keys; }

    bool isValidKey(const std::string& key) const { };

    void addKey(const std::string& key);

private:
    int _size;
    std::string* _keys;
};

// All taken from: https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
struct JSON::JSONKeys::Iterator {
public:
    Iterator(std::string* ptr) : _ptr(ptr) { };

    std::string& operator*() { return *_ptr };
    std::string* operator->() { return _ptr };

    Iterator& operator++() { _ptr++; return *this; }

    Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

    friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

private:
    std::string* _ptr;
};