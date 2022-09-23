#pragma once
#include "JSON.h"

class JSON::JSONObject {
public:
    std::string* keys;

    JSONObject();

    ~JSONObject();

    bool newPair(const std::string& pair);
    bool newPair(const std::string& key, const number& value);
    bool newPair(const std::string& key, const string& value);
    bool newPair(const std::string& key, const JSONObject& object);

    void printAsJSON() const;
    std::string asString() const;

    friend std::ostream& operator<<(std::ostream& os, const JSONObject& object);

private:
    int size;

    JSONObject(JSONObject* object);

    bool newKey(const std::string& key);
    bool isValidKey(const std::string& key) const;

    std::string memberAsString(const int& index, const int& indentation) const;
};
