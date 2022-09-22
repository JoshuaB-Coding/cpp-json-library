#pragma once

#include <iostream>
#include <string>
#include <regex>

namespace JSON {
    class JSONKey;
    class JSONKeys;
    class JSONPairs;
    class JSONObject;
    class JSONParser;

    class CommandLineParser;

    enum FileType { json, txt };
}

#include "JSONKey.h"
#include "JSONKeys.h"
#include "JSONPair.h"
#include "JSONPairs.h"
#include "JSONObject.h"
#include "JSONParser.h"
#include "CommandLineParser.h"