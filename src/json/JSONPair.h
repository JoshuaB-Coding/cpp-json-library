#pragma once
#include "JSON.h"

namespace JSON {
    template<typename T>
    class JSONPair {
    public:
        JSONPair(const JSON::JSONKey& key, const T& value) : _key(key), _value(value) { };
        ~JSONPair() { };

        friend std::ostream& operator<<(std::ostream& os, const JSON::JSONPair<T>& pair) {
            os << pair._key << ": " << pair._value;
            return os;
        };

    private:
        JSON::JSONKey _key;
        T _value;
    };

    // template<typename T>
    // std::ostream& operator<<(std::ostream& os, const JSON::JSONPair<T>& pair) {
    //     os << "\"" << pair._key << "\": " << pair._value;
    //     return os;
    // };
}