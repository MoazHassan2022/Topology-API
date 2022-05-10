#pragma once
#include "ElectronicDevice.h"

/// This class inherits from ElectronicDevice class.
/// 
/// It is responsible for holding Resistance device data.
class Resistance : public ElectronicDevice {
private:
	UI ui;
public:
	/// Constructor.
	///  
	/// Resistance class constructor that calls ElectronicDevice constructor.
	Resistance();
	/// Another constructor.
	/// 
	/// Initializes class data members.
	/// <param name="id">Electronic Device id.</param>
	/// <param name="defaultValue">Default value for the Electronic Device.</param>
	/// <param name="minimumValue">Minimum value for the Electronic Device.</param>
	/// <param name="maximumValue">Maximum value for the Electronic Device.</param>
	Resistance(string id, float defaultValue, float minimumValue, float maximumValue);
	/// Function for prinitng Resistance details.
	/// 
	/// Function for prinitng Resistance details, overrides the base class ElectronicDevice print function.
	virtual void printElectronicDevice();
	/// Destructor
	///
	/// Empty Destructor.
	~Resistance();
};
