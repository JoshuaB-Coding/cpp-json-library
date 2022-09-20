#include "header.h"

int main() {
    JSON::JSONObject object = JSON::JSONObject();
    object.newPair("value", 5.0);
    object.printAsJSON();
    object.newPair("World", 2);
    object.newPair("value", 5);
    // object.printAsJSON();

    std::cout << object << std::endl;

    std::cout << "Hello World!" << std::endl;
    return 0;
}