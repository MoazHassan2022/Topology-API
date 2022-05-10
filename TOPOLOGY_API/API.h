#pragma once
#include "Topology.h"
#include "Resistance.h"
#include "CMOS.h"
/// This is the Manager Class
///
/// This is the core of the project as it integrates between all classes before and have the needed functions to deal with, its data: vector<Topology*> topologyList.
class API {
private:
	vector<Topology*> topologyList;
	int findTopology(string topologyID);
	UI ui;
public:
	/// Constructor.
	/// 
	/// Empty Constructor.
	API();
	/// This function reads the JSON file to the memory.
	/// 
	/// This function reads the JSON file and store its data in the topologyList vector.
	/// <param name="inputFileName">Input JSON File path.</param>
	/// <returns>Boolean: Success or Failure.</returns>
	bool readJSON(string inputFileName);
	/// This function writes the JSON file from the memory.
	/// 
	/// This function writes the JSON file and takes its data from wanted topology from the topologyList vector.
	/// <param name="topologyID">Wanted topology id.</param>
	/// <returns>Boolean: Success or Failure.</returns>
	bool writeJSON(string topologyID);
	/// This function queries all the topologies from the memory.
	/// 
	/// This function queries all the topologies from the topologyList vector.
	/// <returns>vector<Topology*>: All topologies in the memory.</returns>
	vector<Topology*> queryTopologies();
	/// This function deletes a specific topology from the memory.
	/// 
	/// This function deletes a specific topology with id = topologyID from the topologyList vector.
	/// <param name="topologyID">Wanted topology id.</param>
	/// <returns>Boolean: Success or Failure.</returns>
	bool deleteTopology(string topologyID);
	/// This function queries all Eletronic Devices in a specific topology from the memory.
	/// 
	/// This function queries all Eletronic Devices in a specific topology with id = topologyID from the topologyList vector.
	/// <param name="topologyID">Wanted topology id.</param>
	/// <returns>vector<ElectronicDevice*>: Electronic Devices Result.</returns>
	vector<ElectronicDevice*> queryDevices(string topologyID);
	/// This function queries all Eletronic Devices in a specific topology that are connected to a specific node.
	/// 
	/// This function queries all Eletronic Devices in a specific topology with id = topologyID from the topologyList vector, that are connected to a specific node with id = netlistNodeID.
	/// <param name="topologyID">Wanted topology id.</param>
	/// <param name="netlistNodeID">Wanted node id.</param>
	/// <returns>vector<ElectronicDevice*>: Electronic Devices Result.</returns>
	vector<ElectronicDevice*> queryDevicesWithNetlistNode(string topologyID, string netlistNodeID);
	/// Destructor
	///
	/// API class destructor that deletes the topologyList vector.
	~API();
};