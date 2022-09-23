#pragma once
#include "JSON.h"

class JSON::JSONString {
public:
    JSONString(const char* string);
    JSONString(const std::string& string);

    int length() const;

    bool regex_match(const std::regex& pattern) const;
    bool regex_match(const std::string& pattern) const;
    bool regex_match(const char* pattern) const;

    char& operator[](int);

private:
    std::string m_string;
};