#pragma once
#include "JSON.h"

class JSON::JSONObject {
public:
    std::string* keys;

    JSONObject();
    ~JSONObject();

    template<typename T>
    void newPair(const JSON::JSONKey& key, const T& value);
    template<typename T>
    void newPair(const std::string& key, const T& value);

    void printAsJSON() const;
    std::string asString() const;

    friend std::ostream& operator<<(std::ostream& os, const JSONObject& object);

private:
    int _size;
    JSON::JSONKeys _keys;
    JSON::JSONPairs _pairs;

    JSONObject(JSONObject* object);

    bool newKey(const std::string& key);
    bool isValidKey(const std::string& key) const;

    template<typename T>
    void newValue(const T& value);

    std::string memberAsString(const int& index, const int& indentation) const;
};

// Templates can only be defined in header files apparently

template<typename T>
void JSON::JSONObject::newPair(const JSON::JSONKey& key, const T& value) {
    if (newKey(key)) {
        JSONPair<T> pair(key, value);
        _pairs.newPair(pair);
        _size++;
    } else {
        std::cout << "key name '" << key << "' already exists" << std::endl;
    }
};

template<typename T>
void JSON::JSONObject::newPair(const std::string& key, const T& value) {
    const JSONKey jsonKey(key);
    newPair<T>(jsonKey, value);
};

template<typename T>
void JSON::JSONObject::newValue(const T& value) {
    std::cout << "Value: " << value << std::endl;
};
