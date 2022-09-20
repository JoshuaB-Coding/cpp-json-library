#pragma once
#include "../header.h"

namespace JSON {
    class JSONObject;
}

class JSON::JSONObject {
public:
    std::string* keys;

    JSONObject();

    ~JSONObject();

    template<typename T>
    void newPair(const std::string& key, const T& value);

    void printAsJSON();

private:
    int size;

    JSONObject(JSONObject* object);

    bool newKey(const std::string& key);
    bool isValidKey(const std::string& key) const;

    template<typename T>
    void newValue(const T& value);
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