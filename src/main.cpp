#include "header.h"

int main(int argc, char** argv) {
    // JSON::CommandLineParser clParser(argc, argv);

    JSON::JSONKey key("key");
    JSON::JSONPair<int> pair(key, 1);

    std::cout << pair << std::endl;

    return 0;
}