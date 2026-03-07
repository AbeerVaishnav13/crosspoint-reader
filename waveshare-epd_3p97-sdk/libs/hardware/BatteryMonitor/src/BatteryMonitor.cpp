#include "BatteryMonitor.h"
#include <PowerManagementUnit.h>
#include <Arduino.h>

uint16_t BatteryMonitor::readPercentage() const
{
    return PowerManagementUnit::getInstance().getBatteryPercent();
}

uint16_t BatteryMonitor::readMillivolts() const
{
    return PowerManagementUnit::getInstance().getBattVoltage();
}

double BatteryMonitor::readVolts() const
{
    return static_cast<double>(readMillivolts()) / 1000.0;
}
