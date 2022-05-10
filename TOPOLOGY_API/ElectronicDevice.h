#pragma once
#include "UI.h"
/// This class is responsible for holding Electronic Device data.
class ElectronicDevice {
private:
	string id;
	float defaultValue, minimumValue, maximumValue;
	UI ui;
public:
	/// Constructor.
	///  
	/// ElectronicDevice class constructor that intitializes class members.
	ElectronicDevice();
	/// Another constructor.
	/// 
	/// Initializes class data members.
	/// <param name="id">Electronic Device id.</param>
	/// <param name="defaultValue">Default value for the Electronic Device.</param>
	/// <param name="minimumValue">Minimum value for the Electronic Device.</param>
	/// <param name="maximumValue">Maximum value for the Electronic Device.</param>
	ElectronicDevice(string id, float defaultValue, float minimumValue, float maximumValue);
	/// Function for prinitng Electronic Device details.
	/// 
	/// Function for prinitng Electronic Device details, and it is virtual to be overriden by Resistance and CMOS classes.
	virtual void printElectronicDevice();
	/// Function to set device's id.
	/// <param name="id">Device's id.</param>
	void setID(string id);
	/// Function to set device's default value.
	/// <param name="defaultValue">Device's default value.</param>
	void setDefaultValue(float defaultValue);
	/// Function to set device's minimum value.
	/// <param name="minimumValue">Device's minimum value.</param>
	void setMinimumValue(float minimumValue);
	/// Function to set device's maximum value.
	/// <param name="maximumValue">Device's maximum value.</param>
	void setMaximumValue(float maximumValue);
	/// Function to get device's id.
	/// <returns>string: Device's id.</returns>
	string getID() const;
	/// Function to get device's default value.
	/// <returns>float: Device's default value.</returns>
	float getDefaultValue() const;
	/// Function to get device's minimum value.
	/// <returns>float: Device's minimum value.</returns>
	float getMinimumValue() const;
	/// Function to get device's maximum value.
	/// <returns>float: Device's maximum value.</returns>
	float getMaximumValue() const;
	/// Destructor
	///
	/// Empty Destructor.
	~ElectronicDevice();
};
