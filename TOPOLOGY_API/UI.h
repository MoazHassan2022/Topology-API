#pragma once
#include <Windows.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
/// This class is used in all classes that needs to deal with I/O(Input/Output).
class UI{
public:
	/// Constructor.
	/// 
	/// Empty Constructor.
	UI(){}
	/// Function to print any string wuth slow motion.
	/// <param name="s">String to be printed.</param>
	void print(string s);
	/// Function to set the foreground color of the console.
	/// <param name="forgC">Color number.</param>
	void setColor(int forgC);
	/// Destructor.
	///
	/// Empty destructor.
	~UI(){}
};