#pragma once

#include <string>
#include <iostream>

using namespace std;

class CPUplayers {
public:
	int strategy;
	string name;

	CPUplayers(int s, string n);
	void attack();
	void fortify();
	void reinforce();
};