#pragma once
#include "JSON.h"

class JSON::JSONNumber {
public:
    JSONNumber(const int& number);
    JSONNumber(const float& number);
    JSONNumber(const double& number);
    JSONNumber(const std::string& number);
    JSONNumber(const char* number);

    JSONNumber operator+(const JSONNumber& number);

    void operator+=(const JSONNumber& number);
    void operator+=(const double& number);

    JSONNumber& operator++();
    JSONNumber operator++(int);

    friend std::ostream& operator<<(std::ostream& os, const JSONNumber& number);

private:
    double m_number;
};