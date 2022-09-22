#include "JSON.h"

JSON::CommandLineParser::CommandLineParser(const int& argc, char** argv) {
    // Could be worthwhile to accept a --help flag
    try {
        if (argc != 3) throw incorrectNumberOfArguments;
        if (!isFilenameFlag(argv[1])) throw noFilenameFlag;
        if (!setFilename(argv[2])) throw invalidFilename;
    }
    catch (ErrorCode errorCode) {
        switch (errorCode) {
            case incorrectNumberOfArguments:
            std::cout << "Error: expected 3 command line arguments but recieved " << argc << std::endl;
            break;
            case noFilenameFlag:
            std::cout << "Error: expected to find '-f' flag but instead found '" << argv[1] << "'" << std::endl;
            break;
            case invalidFilename:
            std::cout << "Error: filename '" << argv[2] << "' is invalid" << std::endl;
            break;
        }
        return;
    }

    std::cout << "CommandLineParser output: filename '" << filename << "' parsed from command line input" << std::endl;
};

JSON::CommandLineParser::~CommandLineParser() {
    
};

bool JSON::CommandLineParser::isFilenameFlag(const char* flag) const {
    if (flag[0] != '-') return false;
    if (!flag[1]) return false;
    if (flag[1] == 'f' && !flag[2]) return true;
    return false;
};

bool JSON::CommandLineParser::setFilename(const char* filename) {
    std::string filenameAsString(filename);
    if (!isValidFilename(filename)) return false;
    this->filename = filenameAsString;
    return true;
};

bool JSON::CommandLineParser::isValidFilename(const std::string& filename) const {
    const size_t dotIndex = filename.find(".");
    if (dotIndex == 0 || dotIndex == std::string::npos) return false;
    const std::string fileExtension = filename.substr(dotIndex);
    if (fileExtension == ".json" || fileExtension == ".txt") return true;
    return false;
};