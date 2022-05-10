#pragma once
#include <unordered_map> 
#include "ElectronicDevice.h"

/// This class is responsible for holding component's data.
/// 
/// Its data: short type: resistance --> 0, nmos --> 1, pmos --> 2, string id, vector<string> netlist, ElectronicDevice* componentDevice.
class Component {
private:
	short type; // resitor --> 0, nmos --> 1, pmos --> 2
	string id;
	vector<string> netlist; // if component is a resistor so we have 2 elements corresponding to "t1", "t2"
	// if component is a CMOS so we have 3 elements corresponding to "drain", "gate", "source"
	ElectronicDevice* componentDevice; // association
	UI ui;
public:
	/// Constructor.
	///  
	/// Component class constructor that intitializes class members.
	Component();
	/// Another constructor.
	/// 
	/// Initializes class data members.
	/// <param name="type">Component's type: Resistance --> 0, NMOS --> 1, PMOS --> 2</param>
	/// <param name="id">Component's id.</param>
	/// <param name="netlist">Vector of that component connected nodes.</param>
	/// <param name="componentDevice">Pointer of ElectronicDevice class</param>
	Component(short type, string id, const vector<string> &netlist, ElectronicDevice* componentDevice);
	/// Function to set type of the component.
	/// <param name="type">Component's type: Resistance --> 0, NMOS --> 1, PMOS --> 2</param>
	void setType(short type);
	/// Function to set component's id.
	/// <param name="id">Components's id.</param>
	void setID(string id);
	/// Function to set component's netlist vector.
	/// <param name="netlist">Component's netlist vector.</param>
	void setNetlist(const vector<string> &netlist);
	/// Function to set component's ElectronicDevice object pointer.
	/// <param name="componentDevice">Component's ElectronicDevice object pointer.</param>
	void setComponentDevice(ElectronicDevice* componentDevice);
	/// Function to get component's type.
	/// <returns>Component's type: Resistance --> 0, NMOS --> 1, PMOS --> 2</returns>
	short getType();
	/// Function to get component's id.
	/// <returns>Component's id.</returns>
	string getID();
	/// Function to get component's netlist vector.
	/// <returns>Component's netlist vector.</returns>
	vector<string> getNetlist();
	/// Function to push new node ( type: string ) into component's netlist vector.
	/// <param name="node">New node.</param>
	void pushIntoNetlist(string node);
	/// Function to get component's ElectronicDevice object pointer. 
	/// <returns>Component's ElectronicDevice object pointer.</returns>
	ElectronicDevice* getComponentDevice();
	/// Function to print component's details.
	void printComponent();
	/// Destructor
	/// 
	/// Deletes component's ElectronicDevice object pointer and netlist vector.
	~Component();
};
