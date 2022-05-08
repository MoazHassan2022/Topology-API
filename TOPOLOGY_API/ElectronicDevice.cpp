#include "ElectronicDevice.h"

ElectronicDevice::ElectronicDevice(){
	id = "";
	defaultValue = 0;
	minimumValue = 0;
	maximumValue = 0;
}

ElectronicDevice::ElectronicDevice(string id, float defaultValue, float minimumValue, float maximumValue)
{
	this->id = id;
	this->defaultValue = defaultValue;
	this->minimumValue = minimumValue;
	this->maximumValue = maximumValue;
}

void ElectronicDevice::printElectronicDevice()
{
	ui.setColor(11);
	cout << "========================================================================================================================" << endl;
	ui.print("Electronic device with id = "); ui.print(id); cout << ":" << endl;
	ui.print("Default value = "); cout << defaultValue; ui.print(" , Minimum value = "); cout << minimumValue; ui.print(" and Maximum value = "); cout << maximumValue << endl;
	cout << "========================================================================================================================" << endl;
	ui.setColor(6);
}

void ElectronicDevice::setID(string id)
{
	this->id = id;
}

void ElectronicDevice::setDefaultValue(float defaultValue)
{
	this->defaultValue = defaultValue;
}

void ElectronicDevice::setMinimumValue(float minimumValue)
{
	this->minimumValue = minimumValue;
}

void ElectronicDevice::setMaximumValue(float maximumValue)
{
	this->maximumValue = maximumValue;
}

string ElectronicDevice::getID() const
{
	return id;
}

float ElectronicDevice::getDefaultValue() const
{
	return defaultValue;
}

float ElectronicDevice::getMinimumValue() const
{
	return minimumValue;
}

float ElectronicDevice::getMaximumValue() const
{
	return maximumValue;
}

ElectronicDevice::~ElectronicDevice(){}

