#pragma once
#include "API.h"
#include <iostream>
class APITest {
private:
	API api;
	UI ui;
public:

	APITest() {};
	// Each test function returns true if all tests inside it have succeded
	bool readJSONTest();
	bool writeJSONTest();
	bool queryTopologiesTest();
	bool deleteTopologyTest();
	bool queryDevicesTest();
	bool queryDevicesWithNetlistNodeTest();

	~APITest() {};
};
