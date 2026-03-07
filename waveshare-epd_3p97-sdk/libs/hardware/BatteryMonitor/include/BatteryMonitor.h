#pragma once
#include <cstdint>

class BatteryMonitor {
public:
    BatteryMonitor() = default;

    // Read voltage and return percentage (0-100)
    uint16_t readPercentage() const;

    // Read the battery voltage in millivolts
    uint16_t readMillivolts() const;

    // Read the battery voltage in volts
    double readVolts() const;
};
