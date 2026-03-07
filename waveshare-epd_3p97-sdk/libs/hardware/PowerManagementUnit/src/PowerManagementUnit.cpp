#include "PowerManagementUnit.h"

bool PowerManagementUnit::begin(TwoWire& wire, uint8_t sda, uint8_t scl) {
    if (!pmu.begin(wire, AXP2101_SLAVE_ADDRESS, sda, scl)) {
        pmu_initialized = false;
        return false;
    }

    pmu_initialized = true;

    // The Waveshare ESP32-S3 e-Paper 3.97 uses ALDO3 for the e-paper logic/power
    pmu.setALDO3Voltage(3300);
    pmu.enableALDO3();

    // Disable ALDO1 and ALDO2 which power the audio codec, to save power
    pmu.disableALDO1();
    pmu.disableALDO2();

    return true;
}

uint8_t PowerManagementUnit::getBatteryPercent() {
    if (!pmu_initialized) {
        return 0;
    }
    return pmu.getBatteryPercent();
}

uint16_t PowerManagementUnit::getBattVoltage() {
    if (!pmu_initialized) {
        return 0;
    }
    return pmu.getBattVoltage();
}
