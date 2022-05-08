#pragma once
#include <unordered_map> 
#include "ElectronicDevice.h"

class Component {
private:
	short type; // resitor --> 0, nmos --> 1, pmos --> 2
	string id;
	vector<string> netlist; // if component is a resistor so we have 2 elements corresponding to "t1", "t2"
	// if component is a CMOS so we have 3 elements corresponding to "drain", "gate", "source"
	ElectronicDevice* componentDevice; // association
	UI ui;
public:
	Component();
	Component(short type, string id, vector<string> netlist, ElectronicDevice* componentDevice);
	void setType(short type);
	void setID(string id);
	void setNetlist(vector<string> netlist);
	void setComponentDevice(ElectronicDevice* componentDevice);
	short getType();
	string getID();
	vector<string> getNetlist();
	void pushIntoNetlist(string node);
	ElectronicDevice* getComponentDevice();
	void printComponent();
	~Component();
};
