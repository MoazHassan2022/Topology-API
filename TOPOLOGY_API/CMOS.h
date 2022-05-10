#pragma once
#include "ElectronicDevice.h"

/// This class inherits from ElectronicDevice class.
/// 
/// It is responsible for holding CMOS device data.
class CMOS : public ElectronicDevice {
private:
	bool cmosType; // nmos --> 0, pmos --> 1
	UI ui;
public:
	/// Constructor.
	///  
	/// CMOS class constructor that calls ElectronicDevice constructor and intitializes class members.
	CMOS();
	/// Another constructor.
	/// 
	/// Initializes class data members.
	/// <param name="id">Electronic Device id.</param>
	/// <param name="defaultValue">Default value for the Electronic Device.</param>
	/// <param name="minimumValue">Minimum value for the Electronic Device.</param>
	/// <param name="maximumValue">Maximum value for the Electronic Device.</param>
	/// <param name="cmosType">CMOS type: 0 --> NMOS or 1 --> PMOS.</param>
	CMOS(string id, float defaultValue, float minimumValue, float maximumValue, bool cmosType);
	/// Function for prinitng CMOS details.
	/// 
	/// Function for prinitng CMOS details, overrides the base class ElectronicDevice print function.
	virtual void printElectronicDevice();
	/// Function to set CMOS type: NMOS or PMOS.
	/// 
	/// Function to set CMOS type: 0 --> NMOS or 1 --> PMOS.
	/// <param name="type">Input CMOS type.</param>
	void setCMOSType(bool type);
	/// Function to get CMOS type: NMOS or PMOS.
	/// 
	/// Function to get CMOS type: 0 --> NMOS or 1 --> PMOS.
	/// <returns>Boolean: 0 --> NMOS or 1 --> PMOS.</returns>
	bool getCMOSType() const;
	/// Destructor
	///
	/// Empty Destructor.
	~CMOS();
};
