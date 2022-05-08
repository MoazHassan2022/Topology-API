#pragma once
#include "ElectronicDevice.h"

class CMOS : public ElectronicDevice {
private:
	bool cmosType; // nmos --> 0, pmos --> 1
	UI ui;
public:
	CMOS();
	CMOS(string id, float defaultValue, float minimumValue, float maximumValue, bool cmosType);
	virtual void printElectronicDevice();
	void setCMOSType(bool type);
	bool getCMOSType() const;
	~CMOS();
};
