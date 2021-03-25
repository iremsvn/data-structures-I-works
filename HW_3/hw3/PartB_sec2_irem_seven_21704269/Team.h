#pragma once
#ifndef __TEAM__H
#define __TEAM__H
#include <string>
#include "Player.h"
using namespace std;

class Team {

public:
	Team(string nameN = "", string colorN = "", int yearN = 0);
	~Team();
	Team(const Team& teamCopy);
	Team& operator=(const Team& right);
	
private:

	struct Node {
		Player p;
		Node* next;
	};

	Node* head; 
	int playerCount;
	string name;
	string color;
	int year;
	Node* findPlayer(const string playerName) const;
	void removePlayer(const string playerName);
	void addPlayer(const string pName, const string pPosition);
	bool compareStr(const string& str1_, const string& str2_) const;
	void displayPlayers();

	friend class CompleteReg;

};
#endif

