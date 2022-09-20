#pragma once
#include "JSON.h"

class JSON::JSONParser {
public:
    JSONParser();
    ~JSONParser();

    void parseStringToJSON(const std::string& input, JSON::JSONObject* object) const;
    void parseJSONToString(const JSONObject& input, std::string* string) const;

    bool isValidJSONString(const std::string& jsonString) const;

private:
    static const std::regex _regexPattern;
    enum ErrorType { parsingString, parsingJSON };

    void error(ErrorType errorType, const std::string& message) const {
        switch (errorType) {
            case parsingString: std::cout << "Error parsing string to JSON: "; break;
            case parsingJSON: std::cout << "Error parsing JSON to string: "; break;
        }
        std::cout << message << std::endl;
    }

    // bool isValidJSONString(const std::string& jsonString) const;
};