#include "Topology.h"

Topology::Topology(){}

Topology::Topology(string id, const vector<Component*>& componentsList)
{
    this->id = id;
    this->componentsList = componentsList;
}

void Topology::setID(string id)
{
    this->id = id;
}

void Topology::setComponentsList(const vector<Component*>& componentsList)
{
    this->componentsList = componentsList;
}

string Topology::getID()
{
    return id;
}

vector<Component*> Topology::getComponentsList()
{
    return componentsList;
}

void Topology::pushIntoComponentsList(Component* component)
{
    componentsList.push_back(component);
}

void Topology::printTopology()
{
    ui.setColor(11);
    cout << "========================================================================================================================" << endl;
    ui.print("Topology with id = "); ui.print(id); ui.print(", has components:"); cout << endl;
    for (auto component : componentsList)
        component->printComponent();
    ui.setColor(11);
    cout << "========================================================================================================================" << endl;
    ui.setColor(6);
}

Topology::~Topology()
{
    componentsList.~vector<Component*>();
}
