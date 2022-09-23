#pragma once

#include <iostream>
#include <string>
#include <regex>

namespace JSON {
    class JSONKey;
    class JSONKeys;
    class JSONObject;
    class JSONParser;

    class CommandLineParser;

    class JSONNumber;
    typedef JSONNumber number;

    class JSONString;
    typedef JSONString string;

    enum FileType { json, txt };
}

#include "JSONKey.h"
#include "JSONKeys.h"
#include "JSONObject.h"
#include "JSONParser.h"
#include "CommandLineParser.h"
#include "JSONNumber.h"
#include "JSONString.h"