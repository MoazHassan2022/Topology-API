#pragma once
#include "Component.h"

/// This class is responsible for holding topology's data.
/// 
/// Its data: string id and vector<Component*> componentsList.
class Topology {
private:
	string id;
	vector<Component*> componentsList;
	UI ui;
public:
	/// Constructor.
	/// 
	/// Empty Constructor.
	Topology();
	/// Another constructor.
	/// 
	/// Initializes class data members.
	/// <param name="id">Topology's id.</param>
	/// <param name="componentsList">Topology's components list.</param>
	Topology(string id, const vector<Component*>& componentsList);
	/// Function to set toplogy's id.
	/// <param name="id">Topology's id.</param>
	void setID(string id);
	/// Function to set topology's components list.
	/// <param name="componentsList">Topology's components list.</param>
	void setComponentsList(const vector<Component*> &componentsList);
	/// Function to get topology's id.
	/// <returns>Topology's id.</returns>
	string getID();
	/// Function to get topology's components list.
	/// <returns>Topology's components vector of pointers.</returns>
	vector<Component*> getComponentsList();
	/// Function to push component pointer into Topology's components list.
	/// <param name="component"></param>
	void pushIntoComponentsList(Component* component);
	/// Function to print topology's details.
	void printTopology();
	/// Destructor.
	///
	/// Deletes topology's components list vector.
	~Topology();
};
