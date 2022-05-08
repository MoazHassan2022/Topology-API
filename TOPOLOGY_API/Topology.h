#pragma once
#include "Component.h"

class Topology {
private:
	string id;
	vector<Component*> componentsList;
	UI ui;
public:
	Topology();
	Topology(string id, const vector<Component*>& componentsList);
	void setID(string id);
	void setComponentsList(const vector<Component*> &componentsList);
	string getID();
	vector<Component*> getComponentsList();
	void pushIntoComponentsList(Component* component);
	void printTopology();
	~Topology();
};
