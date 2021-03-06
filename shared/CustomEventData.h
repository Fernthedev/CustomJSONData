#pragma once

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/document.h"
#include "custom-types/shared/macros.hpp"
#include "System/Object.hpp"

#include "CJDLogger.h"

namespace CustomJSONData {

class CustomEventData {
public:
    std::string type;
    float time;
    rapidjson::Value *data;
};


struct CustomEventCallbackData {
    void (*callback)(CustomJSONData::CustomEventData *);
    float aheadTime;
    bool callIfBeforeStartTime;
    int nextEventIndex;
};

class CustomEventCallbacks {
public:
    static std::vector<CustomEventCallbackData> customEventCallbacks;

    static void AddCustomEventCallback(void (*callback)(CustomJSONData::CustomEventData *), float aheadTime = 0, bool callIfBeforeStartTime = false);

};

} // end namespace CustomJSONData