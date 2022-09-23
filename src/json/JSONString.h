#pragma once
#include "JSON.h"

class JSON::JSONString {
public:
    JSONString(const char* string) : m_string(string) { };
    JSONString(const std::string& string) : m_string(string) { };

private:
    std::string m_string;
};