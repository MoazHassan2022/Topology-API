#pragma once
#include "ElectronicDevice.h"

class Resistance : public ElectronicDevice {
private:
	UI ui;
public:
	Resistance();
	Resistance(string id, float defaultValue, float minimumValue, float maximumValue);
	virtual void printElectronicDevice();
	~Resistance();
};
