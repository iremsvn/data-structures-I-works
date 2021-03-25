#pragma once
#ifndef __PLAYER__H
#define __PLAYER__H
#include <string>
using namespace std;

class Player {
public:
	Player(string name = "", string position = "");

private:
	string name;
	string position;

	friend class Team;
};
#endif