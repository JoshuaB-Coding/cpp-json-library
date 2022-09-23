#include "JSON.h"

JSON::JSONNumber::JSONNumber(const int& number) : m_number(number) {

};

JSON::JSONNumber::JSONNumber(const float& number) : m_number(number) {

};

JSON::JSONNumber::JSONNumber(const double& number) : m_number(number) {

};

JSON::JSONNumber::JSONNumber(const std::string& number) {
    m_number = atof(number.c_str());
};

JSON::JSONNumber::JSONNumber(const char* number) {
    m_number = atof(number);
};

JSON::JSONNumber JSON::JSONNumber::operator+(const JSON::JSONNumber& number) {
    return this->m_number + number.m_number;
};

void JSON::JSONNumber::operator+=(const JSON::JSONNumber& number) {
    this->m_number += number.m_number;
};

void JSON::JSONNumber::operator+=(const double& number) {
    this->m_number += number;
};

JSON::JSONNumber& JSON::JSONNumber::operator++() {
    this->m_number += 1.0;
    return *this;
};

JSON::JSONNumber JSON::JSONNumber::operator++(int) {
    JSONNumber temp = *this;
    ++*this;
    return temp;
};

std::ostream& JSON::operator<<(std::ostream& os, const JSON::JSONNumber& number) {
    os << number.m_number;
    return os;
};