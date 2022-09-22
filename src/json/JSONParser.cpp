#include "JSON.h"

const std::regex JSON::JSONParser::_regexPattern = std::regex("^{[\"a-zA-Z:{},0-9 ]+}$");

JSON::JSONParser::JSONParser() {

};

JSON::JSONParser::~JSONParser() {
    
};

void JSON::JSONParser::parseStringToJSON(const std::string& input, JSON::JSONObject* object) const {
    if (!this->isValidJSONString(input)) {
        this->error(parsingString, "Invalid input string");
    }
    // TODO: Code to go here
};

void JSON::JSONParser::parseJSONToString(const JSONObject& input, std::string& jsonString) const {
    jsonString.clear();
    jsonString.append("{");
    // TODO: Code to go here
    jsonString.append("}");
};

void JSON::JSONParser::parseFromFile(const JSON::FileType& fileType, const std::string& filename, JSON::JSONObject* object) const {
    // TODO: Code to go here
};

bool JSON::JSONParser::isValidJSONString(const std::string& jsonString) const {
    return std::regex_match(jsonString, _regexPattern);
};

std::string JSON::JSONParser::parseJSONFile(const std::string& filename) const {
    // TODO: Code to go here
    return "";
};

std::string JSON::JSONParser::parseTxtFile(const std::string& filename) const {
    // TODO: Code to go here
    return "";
};