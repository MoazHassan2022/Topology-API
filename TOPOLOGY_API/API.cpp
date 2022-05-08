#include "API.h"
#include <fstream>
#include <json/value.h>
#include <json/json.h>
#include "dist/jsoncpp.cpp"
//#include "dist/json/json.h"
//#include "dist/json/json-forwards.h"
using namespace std;

API::API(){}

bool API::readJSON(string inputFileName)
{
    Json::Reader fileReader;
    Json::Value fileValue;

    // Open the file
    ifstream file(inputFileName + ".json");

    // Parse and if there is an error print it
    if (!fileReader.parse(file, fileValue)) {
        return 0;
    }
    Topology* topology = new Topology();
    topology->setID(fileValue["id"].asString());
    int size = fileValue["components"].size();
    for (int i = 0; i < size; i++) {
        Component* component = new Component();
        // ==============================Get component id==============================
        string componentID = fileValue["components"][i]["id"].asString();
        component->setID(componentID);
        // ==============================Get component type==============================
        string type = fileValue["components"][i]["type"].asString(); // resitor --> 0, nmos --> 1, pmos --> 2
        short componentType = 0;
        if (!strcmp(type.c_str(), "nmos"))
            componentType = 1;
        else if (!strcmp(type.c_str(), "pmos"))
            componentType = 2;
        component->setType(componentType);
        // ==============================Get component netlist==============================
        Json::Value netlist = fileValue["components"][i]["netlist"];
        if (componentType == 0) { // resistor
            component->pushIntoNetlist(netlist["t1"].asString());
            component->pushIntoNetlist(netlist["t2"].asString());
        }
        else { // NMOS or PMOS --> same reading
            component->pushIntoNetlist(netlist["drain"].asString());
            component->pushIntoNetlist(netlist["gate"].asString());
            component->pushIntoNetlist(netlist["source"].asString());
        }
        // ==============================Get component device==============================
        if (componentType == 0) { // resistor
            Resistance* resistance = new Resistance();
            Json::Value resistanceJSON = fileValue["components"][i]["resistance"];
            resistance->setID(componentID);
            resistance->setDefaultValue(resistanceJSON["default"].asFloat());
            resistance->setMinimumValue(resistanceJSON["min"].asFloat());
            resistance->setMaximumValue(resistanceJSON["max"].asFloat());
            component->setComponentDevice(resistance);
        }
        else { // CMOS
            CMOS* cmos = new CMOS();
            Json::Value cmosJSON = fileValue["components"][i]["m(l)"];
            cmos->setID(componentID);
            cmos->setDefaultValue(cmosJSON["default"].asFloat());
            cmos->setMinimumValue(cmosJSON["min"].asFloat());
            cmos->setMaximumValue(cmosJSON["max"].asFloat());
            bool cmosType = (componentType == 1) ? 0 : 1;
            cmos->setCMOSType(cmosType);
            component->setComponentDevice(cmos);
        }
        topology->pushIntoComponentsList(component);

    }
    topologyList.push_back(topology);
    return 1;

}

bool API::writeJSON(string topologyID)
{
    Json::StyledStreamWriter writer;
    ofstream newFile;
    string newFileName;
    int index = findTopology(topologyID);
    if (index == -1) {
        ui.setColor(4);
        ui.print("ERROR: Didn't find a topology with id = "); ui.print(topologyID); cout << endl;
        ui.setColor(6);
        return 0;
    }
    ui.print("Enter the new JSON file name(without .json extension): ");
    cin >> newFileName;
    if (newFileName.empty()) {
        ui.setColor(4);
        ui.print("ERROR: You have entered empty name."); cout << endl;
        ui.setColor(6);
        return 0;
    }
    newFile.open(newFileName + ".json");
    newFile << "{" << endl;
    // ==============================Printing the topology data==============================
    newFile << "  \"id\": \"" << topologyList[index]->getID() << "\"," << endl;

    newFile << "  \"components\": [" << endl;
    vector<Component*> componentList = topologyList[index]->getComponentsList();
    for (int i = 0; i < componentList.size(); i++) {
        // ==============================Printing the component data==============================
        if (i != 0) // Not first component, so add ","
            newFile << "," << endl;
        newFile << "    {" << endl << "      \"type\": \"";
        short type = componentList[i]->getType();
        if(type == 0) // resistor
            newFile << "resistor\"" << "," << endl;
        else if(type == 1) // nmos
            newFile << "nmos\"" << "," << endl;
        else
            newFile << "pmos\"" << "," << endl;
        newFile << "      \"id\": \"" << componentList[i]->getID() << "\"," << endl;
        if (type == 0) // Resistance
            newFile << "      \"resistance\": {" << endl;
        else // CMOS
            newFile << "      \"m(l)\": {" << endl;
        ElectronicDevice* device = componentList[i]->getComponentDevice();
        newFile << "        \"default\": " << device->getDefaultValue() << "," << endl;
        newFile << "        \"min\": " << device->getMinimumValue() << "," << endl;
        newFile << "        \"max\": " << device->getMaximumValue() << endl;
        newFile << "      }," << endl << "      \"netlist\": {" << endl;
        vector<string> netlist = componentList[i]->getNetlist();
        if (type == 0) { // Resistance
            newFile << "        \"t1\": \"" << netlist[0] << "\"," << endl;
            newFile << "        \"t2\": \"" << netlist[1] << "\"" << endl;
        }
        else { // CMOS
            newFile << "        \"drain\": \"" << netlist[0] << "\"," << endl;
            newFile << "        \"gate\": \"" << netlist[1] << "\"," << endl;
            newFile << "        \"source\": \"" << netlist[2] << "\"" << endl;
        }
        // ==============================End of component==============================
        newFile << "      }" << endl << "    }";
    }
    // ==============================End of components list==============================
    newFile << endl << "  ]" << endl;
    // ==============================End of topology==============================
    newFile << "}";
    newFile.close();
    return 1;
}

vector<Topology*> API::queryTopologies()
{
    return topologyList;
}

bool API::deleteTopology(string topologyID)
{
    int index = findTopology(topologyID);
    if (index == -1)
        return 0;
    else {
        delete topologyList[index];
        topologyList.erase(topologyList.begin() + index);
        return 1;
    }
}

vector<ElectronicDevice*> API::queryDevices(string topologyID)
{
    int index = findTopology(topologyID);
    if (index == -1)
        return vector<ElectronicDevice*>();
    vector<ElectronicDevice*> deviceList;
    vector<Component*> componentsList = topologyList[index]->getComponentsList();
    for (int i = 0; i < componentsList.size(); i++)
        deviceList.push_back(componentsList[i]->getComponentDevice());
    return deviceList;
}

vector<ElectronicDevice*> API::queryDevicesWithNetlistNode(string topologyID, string netlistNodeID)
{
    int index = findTopology(topologyID);
    if(index == -1)
        return vector<ElectronicDevice*>();
    vector<ElectronicDevice*> deviceList;
    vector<Component*> componentsList = topologyList[index]->getComponentsList();
    vector<string> netlist;
    for (int i = 0; i < componentsList.size(); i++) {
        netlist = componentsList[i]->getNetlist();
        for (int j = 0; j < netlist.size(); j++) {
            if(!strcmp(netlist[j].c_str(), netlistNodeID.c_str()))
                deviceList.push_back(componentsList[i]->getComponentDevice());
        }
    }
    return deviceList;
}

int API::findTopology(string topologyID)
{
    for (int i = 0; i < topologyList.size(); i++) {
        if (!strcmp(topologyList[i]->getID().c_str(), topologyID.c_str()))
            return i;
    }
    return -1;
}

API::~API()
{
    topologyList.~vector<Topology*>();
}
