#include "header.h"

int main(int argc, char** argv) {
    // JSON::CommandLineParser clParser(argc, argv);
 
    JSON::JSONObject object;
    std::cout << object << std::endl;

    object.newPair("key1", 1);
    object.newPair("key2", 2);

    std::cout << object << std::endl;

    // JSON::JSONParser parser = JSON::JSONParser();
    // std::string jsonString = "{ \"name\": \"John\", \"phone\": 0193 }";

    // std::cout << jsonString << std::endl;

    // std::cout << "Is valid JSON string: " << parser.isValidJSONString(jsonString) << std::endl;
    return 0;
}