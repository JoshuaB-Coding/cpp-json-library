#pragma once
#include "JSON.h"

class JSON::JSONKeys {
public:
    JSONKeys() { _size = 0; }
    ~JSONKeys() { delete[] _keys; }

    struct Iterator {
    public:
        Iterator(std::string* ptr) : _ptr(ptr) { };

        std::string& operator*() { return *_ptr; }
        std::string* operator->() { return _ptr; }

        Iterator& operator++() { _ptr++; return *this; }

        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a._ptr == b._ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a._ptr != b._ptr; };

    private:
        std::string* _ptr;
    };

    Iterator begin() { return Iterator(&_keys[0]); }
    Iterator end() { return Iterator(&_keys[_size]); }

    std::string* getKeys() const { return _keys; }

    bool isValidKey(const std::string& key) const { return true; }

    void addKey(const std::string& key) {
        std::string* newKeys = new std::string[_size + 1];
        for (int i = 0; i < _size; i++) {
            newKeys[i] = _keys[i];
        }
        newKeys[_size] = key;
        delete[] _keys;
        _keys = newKeys;
        _size++;
    }

private:
    int _size;
    std::string* _keys;
};

// All taken from: https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
// struct JSON::JSONKeys::Iterator {
// public:
//     Iterator(std::string* ptr) : _ptr(ptr) { };

//     std::string& operator*() { return *_ptr };
//     std::string* operator->() { return _ptr };

//     Iterator& operator++() { _ptr++; return *this; }

//     Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

//     friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
//     friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

// private:
//     std::string* _ptr;
// };