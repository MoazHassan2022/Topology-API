#include "APITest.h"

bool APITest::readJSONTest()
{
	ui.setColor(6);
	cout << "=================================================TESTING readJSON()=====================================================" << endl;
	int successCounter = 0;
	if (api.readJSON("topology")) {
		ui.setColor(11);
		ui.print("TEST 1 PASSED"); cout << endl;
		successCounter++;
	}
	else {
		ui.setColor(4);
		ui.print("TEST 1 DIDN'T PASS"); cout << endl;
	}
	if (api.readJSON("secondTopology")) {
		ui.setColor(11);
		ui.print("TEST 2 PASSED"); cout << endl;
		successCounter++;
	}
	else {
		ui.setColor(4);
		ui.print("TEST 2 DIDN'T PASS"); cout << endl;
	}
	if (api.readJSON("thirdTopology")) {
		ui.setColor(11);
		ui.print("TEST 3 PASSED"); cout << endl;
		successCounter++;
	}
	else {
		ui.setColor(4);
		ui.print("TEST 3 DIDN'T PASS"); cout << endl;
	}
	if (api.readJSON("dummyTopology")) {
		ui.setColor(4);
		ui.print("TEST 4 DIDN'T PASS"); cout << endl;
	}
	else {
		ui.setColor(11);
		ui.print("TEST 4 PASSED"); cout << endl;
		successCounter++;
	}
	ui.setColor(6);
	if (successCounter == 4) // All tests succeded
		return 1;
	return 0;
}

bool APITest::writeJSONTest()
{
	ui.setColor(6);
	cout << "=================================================TESTING writeJSON()====================================================" << endl;
	int successCounter = 0;
	if (api.writeJSON("top3")) {
		ui.setColor(11);
		ui.print("TEST 1 PASSED"); cout << endl;
		successCounter++;
	}
	else {
		ui.setColor(4);
		ui.print("TEST 1 DIDN'T PASS"); cout << endl;
	}
	ui.setColor(6);
	if (api.writeJSON("top1")) {
		ui.setColor(11);
		ui.print("TEST 2 PASSED"); cout << endl;
		successCounter++;
	}
	else {
		ui.setColor(4);
		ui.print("TEST 2 DIDN'T PASS"); cout << endl;
	}
	ui.setColor(6);
	if (successCounter == 2) // All tests succeded
		return 1;
	return 0;
}

bool APITest::queryTopologiesTest()
{
	ui.setColor(6);
	cout << "=============================================TESTING queryTopologies()==================================================" << endl;
	int successCounter = 0;
	if (!api.queryTopologies().empty()) {
		ui.setColor(11);
		ui.print("TEST 1 PASSED"); cout << endl;
		ui.setColor(6);
		return 1;
	}
	ui.setColor(4);
	ui.print("TEST 1 DIDN'T PASS"); cout << endl;
	return 0;
}

bool APITest::deleteTopologyTest()
{
	ui.setColor(6);
	cout << "==============================================TESTING deleteTopology()==================================================" << endl;
	int successCounter = 0;
	api.deleteTopology("top1");
	bool isDeleted = 1;
	vector<Topology*> allTopologies = api.queryTopologies();
	for (int i = 0; i < allTopologies.size(); i++) {
		if (!strcmp(allTopologies[i]->getID().c_str(), "top1")) {
			isDeleted = 0;
		}
	}
	if (isDeleted) {
		ui.setColor(11);
		ui.print("TEST 1 PASSED"); cout << endl;
		successCounter++;
	}
	else {
		ui.setColor(4);
		ui.print("TEST 1 DIDN'T PASS"); cout << endl;
	}
	api.deleteTopology("top2");
	isDeleted = 1;
	allTopologies = api.queryTopologies();
	for (int i = 0; i < allTopologies.size(); i++) {
		if (!strcmp(allTopologies[i]->getID().c_str(), "top2")) {
			isDeleted = 0;
		}
	}
	if (isDeleted) {
		ui.setColor(11);
		ui.print("TEST 2 PASSED"); cout << endl;
		successCounter++;
	}
	else {
		ui.setColor(4);
		ui.print("TEST 2 DIDN'T PASS"); cout << endl;
	}
	ui.setColor(6);
	if (successCounter == 2)
		return 1;
	return 0;
}

bool APITest::queryDevicesTest()
{
	ui.setColor(6);
	cout << "===============================================TESTING queryDevices()===================================================" << endl;
	int successCounter = 0;
	if (!api.queryDevices("top3").empty()) {
		ui.setColor(11);
		ui.print("TEST 1 PASSED"); cout << endl;
		ui.setColor(6);
		return 1;
	}
	ui.setColor(4);
	ui.print("TEST 1 DIDN'T PASS"); cout << endl;
	return 0;
}

bool APITest::queryDevicesWithNetlistNodeTest()
{
	ui.setColor(6);
	cout << "========================================TESTING queryDevicesWithNetlistNode()===========================================" << endl;
	int successCounter = 0;
	if (!api.queryDevicesWithNetlistNode("top3", "n1").empty()) {
		ui.setColor(11);
		ui.print("TEST 1 PASSED"); cout << endl;
		ui.setColor(6);
		return 1;
	}
	ui.setColor(4);
	ui.print("TEST 1 DIDN'T PASS"); cout << endl;
	return 0;
}
