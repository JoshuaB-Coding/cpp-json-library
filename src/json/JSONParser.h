#pragma once
#include "JSON.h"

class JSON::JSONParser {
public:
    JSONParser();
    ~JSONParser();

    class Tokenizer;

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

class JSON::JSONParser::Tokenizer {
private:
    enum Types { KEY, NUMBER, STRING, OBJECT };
    std::string m_token;
    Types m_tokenType;

    std::string getString() {
        if (m_tokenType != STRING) {
            return "";
        }
        return m_token;
    }

    double getNumber() {
        if (m_tokenType != NUMBER) {
            return -1;
        }
        return std::stod(m_token);
    }

public:
    Tokenizer(const std::string& token) : m_token(token) {
        if (std::regex_match(":$", std::regex(token))) {
            m_tokenType = KEY;
            std::cout << "Tokenizer: Type is KEY" << std::endl;
        }
    }

    
};