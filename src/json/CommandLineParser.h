#pragma once
#include "JSON.h"

class JSON::CommandLineParser {
public:
    CommandLineParser(const int& argc, char** argv);
    ~CommandLineParser();

private:
    enum ErrorCode { incorrectNumberOfArguments, noFilenameFlag, invalidFilename };
    std::string filename;

    bool isFilenameFlag(const char* flag) const;
    bool setFilename(const char* flag);
    bool isValidFilename(const std::string& filename) const;
};