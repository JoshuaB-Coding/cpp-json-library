#include "header.h"

int main(int argc, char** argv) {
    JSON::CommandLineParser clParser(argc, argv);

    // JSON::JSONParser parser = JSON::JSONParser();
    // std::string jsonString = "{ \"name\": \"John\", \"phone\": 0193 }";

    // std::cout << jsonString << std::endl;

    // std::cout << "Is valid JSON string: " << parser.isValidJSONString(jsonString) << std::endl;

    // JSON::JSONKeys keys = JSON::JSONKeys();
    // keys.addKey("key1");
    // keys.addKey("key2");

    // JSON::JSONKey key = JSON::JSONKey("key");
    // keys.addKey(key);

    // std::cout << keys << std::endl;
    return 0;
}