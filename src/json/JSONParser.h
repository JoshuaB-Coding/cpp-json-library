#pragma once
#include "JSON.h"

class JSON::JSONParser {
public:
    JSONParser();
    ~JSONParser();

    void parseStringToJSON(const std::string& input, JSON::JSONObject* object) const;
    void parseJSONToString(const JSONObject& input, std::string& string) const;

    void parseFromFile(const FileType& fileType, const std::string& filename, JSON::JSONObject* object) const;

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

    std::string parseJSONFile(const std::string& filename) const;
    std::string parseTxtFile(const std::string& filename) const;

    // bool isValidJSONString(const std::string& jsonString) const;
};