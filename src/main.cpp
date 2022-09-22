#include "header.h"

int main(int argc, char** argv) {
    // JSON::CommandLineParser clParser(argc, argv);

    JSON::JSONObject object();
    object.newPair<int>("value1", 1);
    object.newPair<int>("value2", 2);

    return 0;
}