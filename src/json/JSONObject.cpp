#include "JSONObject.h"

JSON::JSONObject::JSONObject() {
    this->size = 0;
    this->keys = new std::string[this->size];
};

JSON::JSONObject::~JSONObject() {
    delete[] this->keys;
};

void JSON::JSONObject::printAsJSON() {
    std::cout << "{" << std::endl;
    for (int i = 0; i < this->size; i++) {
        std::cout << "    \"" << keys[i] << "\": NONE" << std::endl;
    }
    std::cout << "}" << std::endl;
};

JSON::JSONObject::JSONObject(JSONObject* object) {
    this->size = object->size;
};

bool JSON::JSONObject::newKey(const std::string& key) {
    if (!isValidKey(key)) {
        return false;
    }
    std::string* newKeys = new std::string[this->size + 1];
    for (int i = 0; i < this->size; i++) {
        newKeys[i] = this->keys[i];
    }
    newKeys[this->size] = key;
    delete[] this->keys;
    this->keys = newKeys;
    return true;
};

bool JSON::JSONObject::isValidKey(const std::string& key) const {
    for (int i = 0; i < this->size; i++) {
        if (this->keys[i] == key) {
            return false;
        }
    }
    return true;
};
