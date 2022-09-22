#include "JSON.h"

JSON::JSONObject::JSONObject() {
    
};

JSON::JSONObject::~JSONObject() {
    
};

void JSON::JSONObject::printAsJSON() const {
    std::cout << "{" << std::endl;
    for (int i = 0; i < _keys.length(); i++) {
        std::cout << "    " << _keys[i] << "\": NONE" << std::endl;
    }
    std::cout << "}" << std::endl;
};

std::string JSON::JSONObject::asString() const {
    std::string jsonString = "{";
    for (int i = 0; i < _keys.length(); i++) {
        jsonString += this->memberAsString(i, 1);
    }
    jsonString += "\n}";
    return jsonString;
};

bool JSON::JSONObject::newKey(const JSON::JSONKey& key) {
    if (!_keys.isValidKey(key)) {
        return false;
    }
    _keys.addKey(key);
    return true;
};

std::string JSON::JSONObject::memberAsString(const int& index, const int& indentation) const {
    std::string output = "\n";
    if (indentation > 0) {
        for (int i = 0; i < indentation; i++) {
            output += "  ";
        }
    }
    std::string keyString = _keys[index].getKey();
    output += "\"" + keyString + "\": NULL";
    return output;
};

std::ostream& JSON::operator<<(std::ostream& os, const JSON::JSONObject& object) {
    os << object.asString() << std::endl;
    return os;
}
