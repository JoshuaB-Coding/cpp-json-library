#pragma once

#include <iostream>
#include <string>
#include <regex>

namespace JSON {
    class JSONObject;
    class JSONParser;

    class CommandLineParser;

    enum FileType { json, txt };
}

#include "JSONObject.h"
#include "JSONParser.h"
#include "CommandLineParser.h"