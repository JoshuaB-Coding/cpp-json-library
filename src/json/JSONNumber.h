#pragma once
#include "JSON.h"

class JSON::JSONNumber {
public:
    JSONNumber(const int& number) : m_number(number) { }
    JSONNumber(const float& number) : m_number(number) { }
    JSONNumber(const double& number) : m_number(number) { }
    JSONNumber(const std::string& number) {
        m_number = atof(number.c_str());
    }
    JSONNumber(const char* number) {
        m_number = atof(number);
    }

    JSONNumber operator+(const JSONNumber& number) {
        return this->m_number + number.m_number;
    }

    void operator+=(const JSONNumber& number) {
        this->m_number += number.m_number;
    }
    void operator+=(const double& number) {
        this->m_number += number;
    }

    JSONNumber& operator++() {
        this->m_number += 1.0;
        return *this;
    }
    JSONNumber operator++(int) {
        JSONNumber temp = *this;
        ++*this;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const JSONNumber& number) {
        os << number.m_number;
        return os;
    }

private:
    double m_number;
};