#include "CMOS.h"

CMOS::CMOS()
{
    ElectronicDevice::ElectronicDevice();
    cmosType = 0; // Assumption: default is nmos.
}

CMOS::CMOS(string id, float defaultValue, float minimumValue, float maximumValue, bool cmosType) : ElectronicDevice(id, defaultValue, minimumValue, maximumValue)
{
    this->cmosType = cmosType;
}

void CMOS::printElectronicDevice()
{
    string cmosTypeWritten = (cmosType) ? "PMOS" : "NMOS";
    ui.setColor(11);
    ui.print("CMOS: "); ui.print(cmosTypeWritten); cout << endl;
    ElectronicDevice::printElectronicDevice();
}

void CMOS::setCMOSType(bool type)
{
    cmosType = type;
}

bool CMOS::getCMOSType() const
{
    return cmosType;
}

CMOS::~CMOS(){}
