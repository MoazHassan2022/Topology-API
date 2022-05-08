#include "Component.h"

Component::Component()
{
}

Component::Component(short type, string id, vector<string> netlist, ElectronicDevice* componentDevice)
{
    this->type = type;
    this->id = id;
    this->netlist = netlist;
    this->componentDevice = componentDevice;
}

void Component::setType(short type)
{
    this->type = type;
}

void Component::setID(string id)
{
    this->id = id;
}

void Component::setNetlist(vector<string> netlist)
{
    this->netlist = netlist;
}

void Component::setComponentDevice(ElectronicDevice* componentDevice)
{
    this->componentDevice = componentDevice;
}

short Component::getType()
{
    return type;
}

string Component::getID()
{
    return id;
}

vector<string> Component::getNetlist()
{
    return netlist;
}

void Component::pushIntoNetlist(string node)
{
    netlist.push_back(node);
}

ElectronicDevice* Component::getComponentDevice()
{
    return componentDevice;
}

void Component::printComponent()
{
    ui.setColor(11);
    cout << "========================================================================================================================" << endl;
    ui.print("Component with id = "); ui.print(id); ui.print(", Device information:"); cout << endl;
    componentDevice->printElectronicDevice();
    ui.setColor(11);
    ui.print("Netlist:"); cout << endl;
    if (type == 0) { // resistor
        ui.print("t1 : "); ui.print(netlist[0]); cout << endl;
        ui.print("t2 : "); ui.print(netlist[1]); cout << endl;
    }
    else { // nmos or pmos --> same printing
        ui.print("drain : "); ui.print(netlist[0]); cout << endl;
        ui.print("gate : "); ui.print(netlist[1]); cout << endl;
        ui.print("source : "); ui.print(netlist[2]); cout << endl;
    }
    cout << "========================================================================================================================" << endl;
    ui.setColor(6);
}

Component::~Component()
{
    delete componentDevice;
    netlist.~vector<string>();
}
