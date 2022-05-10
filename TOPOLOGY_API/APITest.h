#pragma once
#include "API.h"
#include <iostream>
/// This the Testing class for API functions.
class APITest {
private:
	API api;
	UI ui;
public:
	APITest() {};
	// Each test function returns true if all tests inside it have succeded
	/// Test function for readJSON() function.
	bool readJSONTest();
	/// Test function for writeJSON() function.
	bool writeJSONTest();
	/// Test function for queryTopologies() function.
	bool queryTopologiesTest();
	/// Test function for deleteTopology() function.
	bool deleteTopologyTest();
	/// Test function for queryDevices() function.
	bool queryDevicesTest();
	/// Test function for queryDevicesWithNetlistNode() function.
	bool queryDevicesWithNetlistNodeTest();

	~APITest() {};
};
