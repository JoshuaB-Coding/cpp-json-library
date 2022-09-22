#pragma once
#include "JSON.h"

class JSON::JSONPairs {
public:
    JSONPairs();
    ~JSONPairs();

    void newPair(const JSONPair<int>& pair);
    // void newPair(const JSONPair<std::string>& pair);
    // void newPair(const JSONPair<char*>& pair);
    // void newPair(const JSONPair<JSONObject>& pair);

    JSONPair<int>& operator[](const int& index);

private:
    struct IndexedPair {
    public:
        IndexedPair(const int& index, const JSONPair<int>& pair);
        // IndexedPair(const int& index, const JSONPair<std::string>& pair);
        // IndexedPair(const int& index, const JSONPair<char*>& pair);
        // IndexedPair(const int& index, const JSONPair<JSONObject>& pair); // more tricky

        IndexedPair& operator=(const IndexedPair& indexedPair);

    private:
        int _index;
        JSONPair<int> _intPair;
        // JSONPair<std::string> _stringPair = nullptr;
        // JSONPair<char*> _charPair = nullptr;
        // JSON::JSONPair<JSONObject> _objectPair = nullptr;
    };
    
    int _size;
    IndexedPair* _indexedPairs;
};