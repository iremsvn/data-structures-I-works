#include "Team.h"
#include <iostream>

Team::Team(string nameN, string colorN, int yearN) :name(nameN), color(colorN), year(yearN), playerCount(0), head(NULL) {

}

Team::~Team() {
	while (playerCount != 0) {
		removePlayer(head->p.name);
	}
	head = NULL;
}

Team::Team(const Team& teamCopy):playerCount(teamCopy.playerCount), name(teamCopy.name), color(teamCopy.color), year(teamCopy.year) {
	if (playerCount == 0) {
		head = NULL;
	}
	else {
		head = new Node;
		head->p = teamCopy.head->p;
		Node* newPtr = head;

		for (Node* ptr = teamCopy.head->next; ptr != NULL; ptr = ptr->next) {
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->p = ptr->p;
		}
		newPtr->next = NULL;
	}
}

Team& Team::operator=(const Team& right){
	name = right.name;
	color = right.color;
	year = right.year;
	if (&right != this) {
		if (playerCount != right.playerCount) {
			if (playerCount > 0) {
				//remove all
				while (playerCount != 0) {
					removePlayer(head->p.name);
				}
				head = NULL;
			}

			playerCount = right.playerCount;

			if (playerCount == 0)
				head = NULL;

			else {
				head = new Node;
				head->p = right.head->p;
				Node* newPtr = head;

				for (Node* ptr = right.head->next; ptr != NULL; ptr = ptr->next) {
					newPtr->next = new Node;
					newPtr = newPtr->next;
					newPtr->p = ptr->p;
				}
				newPtr->next = NULL;
			}
			return *this;
		}
	}
}

void Team::addPlayer(const string pName, const string pPosition) {
	if (findPlayer(pName) == NULL) {
		Node* newPtr = new Node;
		Player* newP = new Player(pName, pPosition);
		newPtr->p = *newP;
		delete newP; //to avoid memory leak
		newPtr->next = NULL;
		if (playerCount == 0) {
			head = newPtr;
			playerCount++;
			return;
		}
		Node* prev = head;
		while (prev->next != NULL) {
			prev = prev->next;
		}
		prev->next = newPtr;
		playerCount++;
		return;
	}
	cout <<  pName << " already exist in team " << name << endl;
}

void Team::removePlayer(const string playerName) {
	Node* ptr = findPlayer(playerName);
	if (ptr == NULL) {
		cout <<  playerName << " does not exist in team " << name  << endl;
		return;
	}
	if (head == ptr) {
		head = ptr->next;
	}
	else {
		Node* prev = head;
		while (prev->next != ptr) {
			prev = prev->next;
		}
		prev->next = ptr->next;
	}
	delete ptr;
	playerCount--;
}

Team::Node* Team::findPlayer(const string playerName) const {
	Node* cur = head;
	for (int i = 0; i < playerCount; i++) {
		if (compareStr(cur->p.name, playerName)) { //if true player exists
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

bool Team::compareStr(const string& str1_, const string& str2_) const {
	string str1 = str1_;
	string str2 = str2_;
	for (int i = 0; i < str1.size(); i++)
	{
		str1[i] = tolower(str1[i]);
	}

	for (int i = 0; i < str2.size(); i++)
	{
		str2[i] = tolower(str2[i]);
	}

	if (str1 == str2)
		return true;
	else
		return false;
}


void Team::displayPlayers() {
	if (playerCount == 0) {
		cout << "---EMPTY---" << endl;
		return;
	}
	Node* cur = head;
	for (int i = 0; i < playerCount; i++) {
		cout << cur->p.name << ", " << cur->p.position << endl;
		cur = cur->next;
	}
	cout << endl;
}

