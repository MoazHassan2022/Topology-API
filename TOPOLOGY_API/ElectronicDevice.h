#pragma once
#include "UI.h"

class ElectronicDevice {
private:
	string id;
	float defaultValue, minimumValue, maximumValue;
	UI ui;
public:
	ElectronicDevice();
	ElectronicDevice(string id, float defaultValue, float minimumValue, float maximumValue);
	virtual void printElectronicDevice();
	void setID(string id);
	void setDefaultValue(float defaultValue);
	void setMinimumValue(float minimumValue);
	void setMaximumValue(float maximumValue);
	string getID() const;
	float getDefaultValue() const;
	float getMinimumValue() const;
	float getMaximumValue() const;
	~ElectronicDevice();
};
