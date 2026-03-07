#pragma once

#include <Arduino.h>
#include <XPowersLib.h>
#include <Wire.h>

class PowerManagementUnit {
public:
    static PowerManagementUnit& getInstance() {
        static PowerManagementUnit instance;
        return instance;
    }

    // Delete copy and move constructors for singleton
    PowerManagementUnit(const PowerManagementUnit&) = delete;
    PowerManagementUnit& operator=(const PowerManagementUnit&) = delete;
    PowerManagementUnit(PowerManagementUnit&&) = delete;
    PowerManagementUnit& operator=(PowerManagementUnit&&) = delete;

    // Disables audio pins ALDO1/ALDO2 and enables e-paper pin ALDO3 
    bool begin(TwoWire& wire, uint8_t sda, uint8_t scl);

    uint8_t getBatteryPercent();
    uint16_t getBattVoltage();

private:
    PowerManagementUnit() = default;
    
    XPowersAXP2101 pmu;
    bool pmu_initialized = false;
};
