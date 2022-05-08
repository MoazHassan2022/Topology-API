#pragma once
#include "Topology.h"
#include "Resistance.h"
#include "CMOS.h"
class API {
private:
	vector<Topology*> topologyList;
	int findTopology(string topologyID);
	UI ui;
public:

	API();
	bool readJSON(string inputFileName);
	bool writeJSON(string topologyID);
	vector<Topology*> queryTopologies();
	bool deleteTopology(string topologyID);
	vector<ElectronicDevice*> queryDevices(string topologyID);
	vector<ElectronicDevice*> queryDevicesWithNetlistNode(string topologyID, string netlistNodeID);
	~API();
};