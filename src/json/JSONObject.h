#pragma once
#include "JSON.h"

class JSON::JSONObject {
public:
    JSONObject();
    ~JSONObject();

    struct Keys;
    struct Number;
    struct String;

    Keys* m_keys; // TODO: Fix this way of defining m_keys

    template<typename T>
    void newPair(const std::string& key, const T& value);

    void printAsJSON() const;
    std::string asString() const;

    friend std::ostream& operator<<(std::ostream& os, const JSONObject& object);

private:
    int size;

    JSONObject(JSONObject* object);

    bool newKey(const std::string& key);
    bool isValidKey(const std::string& key) const;

    template<typename T>
    void newValue(const T& value);

    std::string memberAsString(const int& index, const int& indentation) const;
};

// Templates can only be defined in header files apparently

template<typename T>
void JSON::JSONObject::newPair(const std::string& key, const T& value) {
    if (this->newKey(key)) {
        this->newValue<T>(value);
        this->size++;
    } else {
        std::cout << "key name '" << key << "' already exists" << std::endl;
    }
};

template<typename T>
void JSON::JSONObject::newValue(const T& value) {
    std::cout << "Value: " << value << std::endl;
};

struct JSON::JSONObject::Keys {
    public:
    Keys();
    ~Keys();

    struct Key;
    struct Iterator;

    bool isValidKey(const std::string& key) const;

    void addKey(const std::string& key);

    Key& operator[](int);

    friend std::ostream& operator<<(std::ostream& os, const Keys& keys);

    Iterator begin();
    Iterator end();

private:
    int _size;
    Key* _keys;

    Keys(const Keys* keys, const Key& newKey);

    void copyKeys(const Key* oldKeys, const int& size, Key* newKeys) const;

    bool isValidKey(const Key& key) const;

    void addKey(const Key& key);
};

struct JSON::JSONObject::Keys::Key {
public:
    Key();
    Key(const std::string& key);
    ~Key();

    Key& operator=(const Key& key);

    std::string asString() const { return _key; }

    friend bool operator==(const Key& key1, const Key& key2);
    friend bool operator!=(const Key& key1, const Key& key2);
    
    friend std::ostream& operator<<(std::ostream& os, const Key& key);

private:
    std::string _key;
};

// All taken from: https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
struct JSON::JSONObject::Keys::Iterator {
public:
    Iterator(Key* ptr);

    Key& operator*();
    Key* operator->();

    Iterator& operator++();

    Iterator operator++(int);

    friend bool operator==(const Iterator& a, const Iterator& b);
    friend bool operator!=(const Iterator& a, const Iterator& b);

private:
    Key* _ptr;
};

struct JSON::JSONObject::Number {

};

struct JSON::JSONObject::String {

};