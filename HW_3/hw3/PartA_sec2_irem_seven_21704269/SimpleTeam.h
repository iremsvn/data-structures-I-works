#pragma once
#ifndef __SIMPLE_TEAM_H
#define __SIMPLE_TEAM_H
#include <string>
using namespace std;

class Team {

public:
	Team(string nameN = "", string colorN = "", int yearN = 0);

private:
	string name;
	string color;
	int year;

	friend class SimpleReg;
};
#endif