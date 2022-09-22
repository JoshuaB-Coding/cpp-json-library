#include "JSON.h"

JSON::JSONObject::JSONObject() {
    this->_size = 0;
    this->keys = new std::string[this->_size];
};

JSON::JSONObject::~JSONObject() {
    delete[] this->keys;
};

void JSON::JSONObject::printAsJSON() const {
    std::cout << "{" << std::endl;
    for (int i = 0; i < this->_size; i++) {
        std::cout << _pairs[i] << std::endl;
    }
    std::cout << "}" << std::endl;
};

std::string JSON::JSONObject::asString() const {
    std::string jsonString = "{";
    for (int i = 0; i < this->_size; i++) {
        jsonString += this->memberAsString(i, 1);
    }
    jsonString += "\n}";
    return jsonString;
};

JSON::JSONObject::JSONObject(JSONObject* object) {
    this->_size = object->_size;
};

bool JSON::JSONObject::newKey(const std::string& key) {
    if (!isValidKey(key)) {
        return false;
    }
    std::string* newKeys = new std::string[this->_size + 1];
    for (int i = 0; i < this->_size; i++) {
        newKeys[i] = this->keys[i];
    }
    newKeys[this->_size] = key;
    delete[] this->keys;
    this->keys = newKeys;
    return true;
};

bool JSON::JSONObject::isValidKey(const std::string& key) const {
    for (int i = 0; i < this->_size; i++) {
        if (this->keys[i] == key) {
            return false;
        }
    }
    return true;
};

std::string JSON::JSONObject::memberAsString(const int& index, const int& indentation) const {
    std::string output = "\n";
    if (indentation > 0) {
        for (int i = 0; i < indentation; i++) {
            output += "  ";
        }
    }
    output += "\"" + this->keys[index] + "\": NULL";
    return output;
};

std::ostream& JSON::operator<<(std::ostream& os, const JSON::JSONObject& object) {
    os << object.asString() << std::endl;
    return os;
}
