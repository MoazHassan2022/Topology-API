#include "Resistance.h"

Resistance::Resistance()
{
	ElectronicDevice::ElectronicDevice();
}

Resistance::Resistance(string id, float defaultValue, float minimumValue, float maximumValue) : ElectronicDevice(id, defaultValue, minimumValue, maximumValue) {}

void Resistance::printElectronicDevice()
{
	ui.setColor(11);
	ui.print("Resistance:"); cout  << endl;
	ElectronicDevice::printElectronicDevice();
}

Resistance::~Resistance(){}
