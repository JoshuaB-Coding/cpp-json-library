#include "JSONKey.h"

JSON::JSONKey::JSONKey(const std::string& key) : _key(key) {
    
};

JSON::JSONKey::~JSONKey() {
    
};

JSON::JSONKey JSON::JSONKey::operator=(const JSON::JSONKey& key) {
    return JSONKey(key);
};

bool JSON::operator==(const JSON::JSONKey& key1, const JSON::JSONKey& key2) {
    return key1._key == key2._key;
};

bool JSON::operator!=(const JSON::JSONKey& key1, const JSON::JSONKey& key2) {
    return key1._key == key2._key;
};