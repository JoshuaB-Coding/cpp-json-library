#include "JSON.h"

JSON::JSONString::JSONString(const char* string) : m_string(string) {

};

JSON::JSONString::JSONString(const std::string& string) : m_string(string) {

};

int JSON::JSONString::length() const {
    return m_string.size();
};

bool JSON::JSONString::regex_match(const std::regex& pattern) const {
    return std::regex_match(m_string, pattern);
};

bool JSON::JSONString::regex_match(const std::string& pattern) const {
    return regex_match(std::regex(pattern));
};

bool JSON::JSONString::regex_match(const char* pattern) const {
    return regex_match(std::regex(pattern));
};

char& JSON::JSONString::operator[](int index) {
    if (index < 0 || index >= m_string.size()) {
        std::cout << "JSON::JSONString::operator[]: index exceeds bounds of string. Exitting" << std::endl;
        exit(1);
    }
    return m_string[index];
};