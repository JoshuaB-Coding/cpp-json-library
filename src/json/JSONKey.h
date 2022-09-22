#pragma once
#include "JSON.h"

class JSON::JSONKey {
public:
    JSONKey();
    JSONKey(const std::string& key);
    // ~JSONKey();

    JSONKey& operator=(const JSONKey& key);

    friend bool operator==(const JSONKey& key1, const JSONKey& key2);
    friend bool operator!=(const JSONKey& key1, const JSONKey& key2);

    std::string keyValue() const { return _key; }

private:
    std::string _key;
};

// bool JSON::operator==(const JSON::JSONKey& key1, const JSON::JSONKey& key2);
// bool JSON::operator!=(const JSON::JSONKey& key1, const JSON::JSONKey& key2);