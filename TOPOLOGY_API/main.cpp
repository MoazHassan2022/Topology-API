#include "API.h"
#include "APITest.h"

int main() {
	API api;
	UI ui;
	string topologyID, fileName, netlistNodeID;
	vector<Topology*> allTopologies;
	vector<ElectronicDevice*> allDevices;
	APITest apiTest;
	int i;
	ui.setColor(11); // 4 -> red, 6 -> yellow
	cout << "===============================================WELCOME TO TOPOLOGY-API==================================================" << endl;
	short option = 1; // Default: read json file
	// choice = 0 --> close, 1 --> readJSON(), 2 --> writeJSON() 3 --> queryTopologies(), 4 --> deleteTopology(),
	// 5 --> queryDevices(), 6 --> queryDevicesWithNetlistNode(), 7 --> TESTING
	while (option != 0) {
		ui.setColor(6);
		cout << "========================================================================================================================" << endl;
		ui.print("You can use these options(enter the number corresponding to the option):"); cout << endl;
		ui.print("0- Exit the application."); cout << endl;
		ui.print("1- Read a certain topology from a JSON file and store it in the memory."); cout << endl;
		ui.print("2- Write a certain topology from the memory to a JSON file."); cout << endl;
		ui.print("3- Query about which topologies are currently in the memory."); cout << endl;
		ui.print("4- Delete a certain topology from memory."); cout << endl;
		ui.print("5- Query about which devices are in a certain topology."); cout << endl;
		ui.print("6- Query about which devices are connected to a certain netlist node in a certain topology."); cout << endl;
		ui.print("7- Test API functions."); cout << endl;
		cout << "========================================================================================================================" << endl;
		ui.print("Option:");
		cin >> option;
		switch (option) {
		case 0:
			return 0;
		case 1:
			cout << endl; ui.print("Option detected: (1)"); cout << endl;
			ui.print("Enter the JSON file name(without .json extension): ");
			cin >> fileName;
			if (api.readJSON(fileName)) {
				ui.setColor(11);
				cout << endl; ui.print("Successfully added the topology to the memory."); cout << endl;
				ui.setColor(6);
			}
			else {
				ui.setColor(4);
				cout << endl; ui.print("ERROR: There is an error in finding the JSON file or parsing it."); cout << endl;
				ui.setColor(6);
			}
			break;
		case 2:
			cout << endl; ui.print("Option detected: (2)"); cout << endl;
			ui.print("Enter the topology id: ");
			cin >> topologyID;
			if (api.writeJSON(topologyID)) {
				ui.setColor(11);
				cout << endl; ui.print("Successfully wrote the topology to the file."); cout << endl;
				ui.setColor(6);
			}
			break;
		case 3:
			cout << endl; ui.print("Option detected: (3)"); cout << endl;
			allTopologies = api.queryTopologies();
			if (allTopologies.empty()) {
				ui.setColor(4);
				ui.print("ERROR: There is no topology in the memory."); cout << endl;
				ui.setColor(6);
				break;
			}
			ui.setColor(11);
			ui.print("All topologies:"); cout << endl;
			for (i = 0; i < allTopologies.size(); i++) {
				allTopologies[i]->printTopology();
			}
			ui.setColor(6);
			break;
		case 4:
			cout << endl; ui.print("Option detected: (4)"); cout << endl;
			ui.print("Enter the topology id: ");
			cin >> topologyID;
			if (api.deleteTopology(topologyID)) {
				ui.setColor(11);
				cout << endl; ui.print("Successfully deleted the topology from the memory."); cout << endl;
				ui.setColor(6);
			}
			else {
				ui.setColor(4);
				ui.print("ERROR: Didn't find a topology with id = "); ui.print(topologyID); cout << endl;
				ui.setColor(6);
			}
			break;
		case 5:
			cout << endl; ui.print("Option detected: (5)"); cout << endl;
			ui.print("Enter the topology id: ");
			cin >> topologyID;
			allDevices = api.queryDevices(topologyID);
			if (allDevices.empty()) {
				ui.setColor(4);
				cout << endl; ui.print("ERROR: There is no device in this topology or no toplogy exists with id = "); ui.print(topologyID); cout << endl;
				ui.setColor(6);
				break;
			}
			ui.setColor(11);
			cout << endl; ui.print("All devices in topology with id = "); ui.print(topologyID); cout << ":" << endl;
			for (i = 0; i < allDevices.size(); i++) {
				allDevices[i]->printElectronicDevice();
			}
			ui.setColor(6);
			break;
		case 6:
			cout << endl; ui.print("Option detected: (6)"); cout << endl;
			ui.print("Enter the topology id: ");
			cin >> topologyID;
			cout << endl; ui.print("Enter the netlist node id: ");
			cin >> netlistNodeID;
			allDevices = api.queryDevicesWithNetlistNode(topologyID, netlistNodeID);
			if (allDevices.empty()) {
				ui.setColor(4);
				ui.print("ERROR: Wrong netlist node id = "); ui.print(netlistNodeID); ui.print(" or no toplogy exists with id = "); ui.print(topologyID); cout << endl;
				ui.setColor(6);
				break;
			}
			ui.setColor(11);
			ui.print("All devices in toplogy with id = "); ui.print(topologyID); ui.print(" and conncted with netlist node with id = "); ui.print(netlistNodeID); cout << ":" << endl;
			for (i = 0; i < allDevices.size(); i++) {
				allDevices[i]->printElectronicDevice();
			}
			ui.setColor(6);
			break;
		case 7:
			ui.setColor(6);
			cout << endl; ui.print("Option detected: (7)"); cout << endl;
			cout << "========================================================TESTING=========================================================" << endl;
			if (apiTest.readJSONTest()) {
				ui.setColor(11);
				ui.print("readJSON tests succeeded!"); cout << endl;
			}
			else {
				ui.setColor(4);
				ui.print("readJSON tests failed!"); cout << endl;
			}
			if (apiTest.writeJSONTest()) {
				ui.setColor(11);
				ui.print("writeJSON tests succeeded!"); cout << endl;
			}
			else {
				ui.setColor(4);
				ui.print("writeJSON tests failed!"); cout << endl;
			}
			if (apiTest.queryTopologiesTest()) {
				ui.setColor(11);
				ui.print("queryTopologies test succeeded!"); cout << endl;
			}
			else {
				ui.setColor(4);
				ui.print("readJSON test failed!"); cout << endl;
			}
			if (apiTest.deleteTopologyTest()) {
				ui.setColor(11);
				ui.print("deleteTopology tests succeeded!"); cout << endl;
			}
			else {
				ui.setColor(4);
				ui.print("deleteTopology tests failed!"); cout << endl;
			}
			if (apiTest.queryDevicesTest()) {
				ui.setColor(11);
				ui.print("queryDevices test succeeded!"); cout << endl;
			}
			else {
				ui.setColor(4);
				ui.print("queryDevices test failed!"); cout << endl;
			}
			if (apiTest.queryDevicesWithNetlistNodeTest()) {
				ui.setColor(11);
				ui.print("queryDevicesWithNetlistNode test succeeded!"); cout << endl;
			}
			else {
				ui.setColor(4);
				ui.print("queryDevicesWithNetlistNode test failed!"); cout << endl;
			}
		default:
			break;
		}
	}
















	/*if (api.readJSON("topology.json"))
		api.queryTopologies()[0]->printTopology();
	api.writeJSON(topologyID);
	if (api.deleteTopology(topologyID)) {
		vector<Topology*> topologies = api.queryTopologies();
		if (topologies.empty())
			cout << "Deleted Successfully" << endl;
	}
	if (api.readJSON("topology.json"))
		api.queryTopologies()[0]->printTopology();
	vector<ElectronicDevice*> deviceList = api.queryDevices(topologyID);
	for (int i = 0; i < deviceList.size(); i++)
		deviceList[i]->printElectronicDevice();
	deviceList = api.queryDevicesWithNetlistNode(topologyID, "vin");
	for (int i = 0; i < deviceList.size(); i++)
		deviceList[i]->printElectronicDevice();
	deviceList = api.queryDevicesWithNetlistNode(topologyID, "n1");
	for (int i = 0; i < deviceList.size(); i++)
		deviceList[i]->printElectronicDevice();
	deviceList = api.queryDevicesWithNetlistNode(topologyID, "vdd");
	for (int i = 0; i < deviceList.size(); i++)
		deviceList[i]->printElectronicDevice();
	return 0;*/
}