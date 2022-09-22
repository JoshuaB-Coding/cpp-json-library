#pragma once
#include "JSON.h"

class JSON::JSONKey {
public:
    JSONKey();
    JSONKey(const std::string& key);
    ~JSONKey();

    JSONKey& operator=(const JSONKey& key);

    friend bool operator==(const JSONKey& key1, const JSONKey& key2);
    friend bool operator!=(const JSONKey& key1, const JSONKey& key2);
    
    friend std::ostream& operator<<(std::ostream& os, const JSONKey& key);

    std::string getKey() const;

private:
    std::string _key;
};