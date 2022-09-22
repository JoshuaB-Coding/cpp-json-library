#pragma once
#include "JSON.h"

class JSON::JSONObject {
public:
    JSONObject();
    ~JSONObject();

    template<typename T>
    void newPair(const std::string& key, const T& value);

    void printAsJSON() const;
    std::string asString() const;

    friend std::ostream& operator<<(std::ostream& os, const JSONObject& object);

private:
    JSON::JSONKeys _keys;

    bool newKey(const JSON::JSONKey& key);

    template<typename T>
    void newValue(const T& value);

    std::string memberAsString(const int& index, const int& indentation) const;
};

// Templates can only be defined in header files apparently

template<typename T>
void JSON::JSONObject::newPair(const std::string& key, const T& value) {
    // if (this->newKey(key)) {
    //     this->newValue<T>(value);
    //     this->size++;
    // } else {
    //     std::cout << "key name '" << key << "' already exists" << std::endl;
    // }
};

template<typename T>
void JSON::JSONObject::newValue(const T& value) {
    std::cout << "Value: " << value << std::endl;
};
