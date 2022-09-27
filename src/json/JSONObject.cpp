#include "JSONObject.h"

// TODO: All this needs ordering correctly
// TODO: (*m_keys) is very dangerous and I need to be careful 
// TODO: Segmentation fault 11 keeps appearing in addKey() method - no memory on mac?

JSON::JSONObject::JSONObject() {
    this->size = 0;
};

JSON::JSONObject::~JSONObject() {
    // delete this->m_keys; // Do I need this?
};

void JSON::JSONObject::printAsJSON() const {
    std::cout << "{" << std::endl;
    for (int i = 0; i < this->size; i++) {
        std::cout << "    \"" << (*m_keys)[i] << "\": NONE" << std::endl;
    }
    std::cout << "}" << std::endl;
};

std::string JSON::JSONObject::asString() const {
    std::string jsonString = "{";
    for (int i = 0; i < this->size; i++) {
        jsonString += this->memberAsString(i, 1);
    }
    jsonString += "\n}";
    return jsonString;
};

JSON::JSONObject::JSONObject(JSONObject* object) {
    this->size = object->size;
};

bool JSON::JSONObject::newKey(const std::string& key) {
    if (!isValidKey(key)) {
        return false;
    }
    m_keys->addKey(key);
    return true;
};

bool JSON::JSONObject::isValidKey(const std::string& key) const {
    for (int i = 0; i < this->size; i++) {
        if ((*m_keys)[i] == key) {
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
    output += "\"" + (*m_keys)[index].asString() + "\": NULL";
    return output;
};

std::ostream& JSON::operator<<(std::ostream& os, const JSON::JSONObject& object) {
    os << object.asString();
    return os;
};

JSON::JSONObject::Keys::Keys() : _size(0) {

};

JSON::JSONObject::Keys::~Keys() {
    delete[] _keys;
};

JSON::JSONObject::Keys::Iterator JSON::JSONObject::Keys::begin() {
    return Iterator(&_keys[0]);
};

JSON::JSONObject::Keys::Iterator JSON::JSONObject::Keys::end() {
    return Iterator(&_keys[_size]);
};

bool JSON::JSONObject::Keys::isValidKey(const std::string& key) const {
    Key queryKey = Key(key);
    return isValidKey(queryKey);
};

bool JSON::JSONObject::Keys::isValidKey(const JSON::JSONObject::Keys::Key& key) const {
    for (int i = 0; i < _size; i++) {
        if (key == _keys[i]) return false;
    }
    return true;
};

void JSON::JSONObject::Keys::addKey(const std::string& key) {
    Key newKey = Key(key);
    addKey(newKey);
};

JSON::JSONObject::Keys::Keys(const Keys* keys, const Key& newKey) {
    _size = keys->_size + 1;
    _keys = new Key[_size];
    for (int i = 0; i < keys->_size; i++) {
        _keys[i] = keys->_keys[i];
    }
    _keys[keys->_size] = newKey;
};

void JSON::JSONObject::Keys::addKey(const Key& key) {
    Keys newKeys(this, key);
    delete[] _keys;
    _keys = newKeys._keys; // TODO: this is a lazy method
};

JSON::JSONObject::Keys::Key& JSON::JSONObject::Keys::operator[](int index) {
    if (index < 0 || index >= _size) {
        std::cout << "Key::operator[] - invalid index" << std::endl;
        exit(1);
    }
    return _keys[index];
};

void JSON::JSONObject::Keys::copyKeys(const JSON::JSONObject::Keys::Key* oldKeys, const int& size, JSON::JSONObject::Keys::Key* newKeys) const {
    for (int i = 0; i < size; i++) {
        newKeys[i] = oldKeys[i];
    }
};

std::ostream& JSON::operator<<(std::ostream& os, const JSON::JSONObject::Keys& keys) {
    if (keys._size == 0) {
        os << "No keys present";
        return os;
    }
    os << "List of keys: [";
    for (int i = 0; i < keys._size; i++) {
        os << "\n    " << keys._keys[i];
    }
    os << "\n]";
    return os;
};

JSON::JSONObject::Keys::Iterator::Iterator(JSON::JSONObject::Keys::Key* ptr) : _ptr(ptr) {

};

JSON::JSONObject::Keys::Key& JSON::JSONObject::Keys::Iterator::operator*() {
    return *_ptr;
};

JSON::JSONObject::Keys::Key* JSON::JSONObject::Keys::Iterator::operator->() {
    return _ptr;
};

JSON::JSONObject::Keys::Iterator& JSON::JSONObject::Keys::Iterator::operator++() {
    _ptr++;
    return *this;
};

JSON::JSONObject::Keys::Iterator JSON::JSONObject::Keys::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
};

bool JSON::operator==(const JSON::JSONObject::Keys::Iterator& a, const JSON::JSONObject::Keys::Iterator& b) {
    return a._ptr == b._ptr;
};

bool JSON::operator!=(const JSON::JSONObject::Keys::Iterator& a, const JSON::JSONObject::Keys::Iterator& b) {
    return a._ptr != b._ptr;
};

JSON::JSONObject::Keys::Key::Key() {

};

JSON::JSONObject::Keys::Key::Key(const std::string& key) : _key(key) {
    
};

JSON::JSONObject::Keys::Key::~Key() {
    
};

JSON::JSONObject::Keys::Key& JSON::JSONObject::Keys::Key::operator=(const JSON::JSONObject::Keys::Key& key) {
    if (this == &key) return *this;
    _key = key._key;
    return *this;
};

bool JSON::operator==(const JSON::JSONObject::Keys::Key& key1, const JSON::JSONObject::Keys::Key& key2) {
    return key1._key == key2._key;
};

bool JSON::operator!=(const JSON::JSONObject::Keys::Key& key1, const JSON::JSONObject::Keys::Key& key2) {
    return key1._key != key2._key;
};

std::ostream& JSON::operator<<(std::ostream& os, const JSON::JSONObject::Keys::Key& key) {
    os << "\"" << key._key << "\"";
    return os;
};