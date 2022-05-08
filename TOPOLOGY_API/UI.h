#pragma once
#include <Windows.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
class UI{
public:
	UI(){}
	void print(string s);
	void setColor(int forgC);
	~UI(){}
};