#pragma once
#include "JSON.h"

class JSON::JSONObject {
public:
    JSONObject();
    ~JSONObject();

    struct Keys;
    struct Number;
    struct String;
    struct Array;

    template<typename T>
    void newPair(const std::string& key, const T& value);

    void printAsJSON() const;
    std::string asString() const;

    friend std::ostream& operator<<(std::ostream& os, const JSONObject& object);

private:
    int size;
    Keys* m_keys;

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

    struct Iterator;

    bool isValidKey(const std::string& key) const;

    void addKey(const std::string& key);

    std::string& operator[](int);

    friend std::ostream& operator<<(std::ostream& os, const Keys& keys);

    Iterator begin();
    Iterator end();

private:
    int _size;
    std::string* _keys;

    void copyKeys(const std::string* oldKeys, std::string* newKeys, const int& size) const;
};

// All taken from: https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
struct JSON::JSONObject::Keys::Iterator {
public:
    Iterator(std::string* ptr);

    std::string& operator*();
    std::string* operator->();

    Iterator& operator++();

    Iterator operator++(int);

    friend bool operator==(const Iterator& a, const Iterator& b);
    friend bool operator!=(const Iterator& a, const Iterator& b);

private:
    std::string* _ptr;
};

struct JSON::JSONObject::Number {

};

struct JSON::JSONObject::String {

};

struct JSON::JSONObject::Array {

};