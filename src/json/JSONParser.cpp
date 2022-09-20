#include "JSONParser.h"

const std::regex JSON::JSONParser::_regexPattern = std::regex("^[\"a-zA-Z:{},0-9 ]+$");

JSON::JSONParser::JSONParser() {

};

JSON::JSONParser::~JSONParser() {
    
};

void JSON::JSONParser::parseStringToJSON(const std::string& input, JSON::JSONObject* object) const {
    if (!this->isValidJSONString(input)) {
        this->error(parsingString, "Invalid input string");
    }
    
};

void JSON::JSONParser::parseJSONToString(const JSONObject& input, std::string* jsonString) const {

};

bool JSON::JSONParser::isValidJSONString(const std::string& jsonString) const {
    return std::regex_match(jsonString, _regexPattern);
};