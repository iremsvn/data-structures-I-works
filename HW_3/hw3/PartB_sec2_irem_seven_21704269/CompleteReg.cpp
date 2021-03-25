#include "CompleteReg.h"
#include <iostream>

CompleteReg::CompleteReg() :head(NULL), teamCount(0) {

}

CompleteReg::~CompleteReg() {
	while (teamCount != 0) {
		removeTeam(head->t.name);
	}
	head = NULL;
}


CompleteReg::CompleteReg(const CompleteReg& systemToCopy):teamCount(systemToCopy.teamCount) {
	if (teamCount == 0) {
		head = NULL;
	}
	else {
		head = new Node;
		head->t = systemToCopy.head->t;
		Node* newPtr = head;

		for (Node* ptr = systemToCopy.head->next; ptr != NULL; ptr = ptr->next) {
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->t = ptr->t;
		}
		newPtr->next = NULL;
	}
}

CompleteReg& CompleteReg::operator=(const CompleteReg& right) {
	if (&right != this) {
		if (teamCount != right.teamCount) {
			if (teamCount > 0) {
				//remove all
				while (teamCount != 0) {
					removeTeam(head->t.name);
				}
				head = NULL;
			}

			teamCount = right.teamCount;

			if (teamCount == 0)
				head = NULL;

			else {
				head = new Node;
				head->t = right.head->t;
				Node* newPtr = head;

				for (Node* ptr = right.head->next; ptr != NULL; ptr = ptr->next) {
					newPtr->next = new Node;
					newPtr = newPtr->next;
					newPtr->t = ptr->t;
				}
				newPtr->next = NULL;
			}
			return *this;
		}
	}
}


Team& CompleteReg::operator[](const int index) {
	if (index < 0 || index >= teamCount) 
		throw out_of_range("invalid index");
	else {
		Node* ptr = head;
		for (int i = 0; i < teamCount; i++) {
			if (i == index) {
				return ptr->t;
			}
			ptr = ptr->next;
		}
	}
}

void CompleteReg::addTeam(const string tName, const string tColor, const int tyear) {
	if (tyear < 1800 || tyear > 2020) {
		cout << "Invalid Year Entered" << endl;
		return;
	}
	if (findTeam(tName) == NULL) {
		Node* newPtr = new Node;
		Team* newT = new Team(tName, tColor, tyear);
		newPtr->t = *newT;
		delete newT; //to avoid memory leak
		newPtr->next = NULL;
		if (teamCount == 0) {
			head = newPtr;
			teamCount++;
			return;
		}
		Node* prev = head;
		while (prev->next != NULL) {
			prev = prev->next;
		}
		prev->next = newPtr;
		teamCount++;
		return;
	}
	cout << "Team Already Exist" << endl;
}

void CompleteReg::removeTeam(const string teamName) {
	Node* ptr = findTeam(teamName);
	if (ptr == NULL) {
		cout << "Team Does Not Exist" << endl;
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
	teamCount--;
}

void CompleteReg::displayAllTeams() const {
	cout << endl;
	if (teamCount == 0) {
		cout << "---EMPTY---" << endl;
		return;
	}
	Node* cur = head;
	for (int i = 0; i < teamCount; i++) {
		cout << "team: " << cur->t.name << ", color: " << cur->t.color << ", year: " << cur->t.year << endl;
		cur = cur->next;
	}
	cout << endl;
}

CompleteReg::Node* CompleteReg::findTeam(const string teamName) const {
	Node* cur = head;
	for (int i = 0; i < teamCount; i++) {
		if (compareStr(cur->t.name, teamName)) { //if true team exists
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

bool CompleteReg::compareStr(const string& str1_, const string& str2_) const {
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

void CompleteReg::displayTeam(const string teamName) const{
	cout << endl;
	Node* ptr = findTeam(teamName);
	if (ptr == NULL) {
		cout << "team : " << teamName << " does not exist" << endl;
		return;
	}
	cout << ptr->t.name << ", " << ptr->t.color << ", "<< ptr->t.year <<endl;
	ptr->t.displayPlayers();
}

void CompleteReg::addPlayer(const string tName, const string pName, const string pPosition) {
	cout << endl;
	Node* ptr = findTeam(tName);
	if (ptr == NULL) {
		cout << "team: " << tName << " does not exist" << endl;
		return;
	}
	ptr->t.addPlayer(pName, pPosition);
}

void CompleteReg::removePlayer(const string teamName, const string playerName) {
	Node* ptr = findTeam(teamName);
	cout << endl;
	if (ptr == NULL) {
		cout << "team: " << teamName << " does not exist" << endl;
		return;
	}
	ptr->t.removePlayer(playerName);
}

void CompleteReg::displayPlayer(const string playerName) const {
	cout << playerName << endl;
	Node* ptr = head;
	bool flag = false;
	for (int i = 0; i < teamCount; i++) {
		if (ptr->t.findPlayer(playerName) != NULL) {
			cout << ptr->t.name << ", " << ptr->t.color << ", " << ptr->t.year << endl;
			flag = true;
		}
		ptr = ptr->next;
	}
	if (flag == false)
		cout << "---EMPTY---" << endl;
}