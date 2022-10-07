#include "JSON.h"

const std::regex JSON::JSONParser::_regexPattern = std::regex("^[\"a-zA-Z:{},0-9 ]+$"); // "^{[\"a-zA-Z:{},0-9 ]+}$"

JSON::JSONParser::JSONParser() {

};

JSON::JSONParser::~JSONParser() {
    
};

void JSON::JSONParser::parseStringToJSON(const std::string& input, JSON::JSONObject* object) const {
    std::string jsonString = input;
    if (!this->isValidJSONString(input)) {
        this->error(parsingString, "Invalid input string");
    }

    while (jsonString.find(" ") != std::string::npos) {
        int tokenEnd = jsonString.find(" ");
        std::string token = jsonString.substr(0, tokenEnd);
        std::cout << token << std::endl;

        Tokenizer tokenizer(token);

        jsonString.erase(jsonString.begin(), jsonString.begin() + tokenEnd + 1);
    }

    // int keyStart = jsonString.find_first_of("\"");
    // int objectStart = jsonString.substr(1).find_first_of("{");
    // int pairEnd = jsonString.find_first_of(",");
    // while (pairEnd != std::string::npos) {
    //     for (int i = keyStart; i < pairEnd; i++) {
    //         std::cout << jsonString[i];
    //     }
    //     std::cout << std::endl;

    //     jsonString.substr(keyStart, pairEnd);

    //     if (objectStart != std::string::npos) {
    //         if (objectStart < pairEnd) {
    //             // TODO: call parseStringToJSON - this is quite hard to do
    //             std::cout << "OBJECT FOUND!" << std::endl;
    //         }
    //     }

    //     jsonString.erase(jsonString.begin(), jsonString.begin() + pairEnd + 1);

    //     keyStart = jsonString.find_first_of("\"");
    //     pairEnd = jsonString.find_first_of(",");
    // }
    // for (int i = keyStart; i < jsonString.size() - 1; i++) {
    //     std::cout << jsonString[i];
    // }
    // std::cout << std::endl;
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