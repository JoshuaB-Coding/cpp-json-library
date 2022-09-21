#pragma once
#include "JSON.h"

class JSON::JSONKey {
public:
    JSONKey() { };
    JSONKey(const std::string& key);
    ~JSONKey();

    JSONKey operator=(const JSONKey& key);

    friend bool operator==(const JSONKey& key1, const JSONKey& key2);
    friend bool operator!=(const JSONKey& key1, const JSONKey& key2);

    std::string keyValue() const { return _key; }

private:
    const std::string _key;
};