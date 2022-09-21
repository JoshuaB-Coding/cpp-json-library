#include "header.h"

int main() {
    JSON::JSONParser parser = JSON::JSONParser();
    std::string jsonString = "{ \"name\": \"John\", \"phone\": 0193 }";

    std::cout << jsonString << std::endl;

    std::cout << "Is valid JSON string: " << parser.isValidJSONString(jsonString) << std::endl;

    JSON::JSONKeys keys = JSON::JSONKeys();
    keys.addKey("key1");
    keys.addKey("key2");

    for (JSON::JSONKey key: keys) {
        std::cout << key.keyValue() << std::endl;
    }

    std::cout << "Hello World!" << std::endl;
    return 0;
}