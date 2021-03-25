#include "SimpleReg.h"
#include <iostream>

SimpleReg::SimpleReg():head(NULL), teamCount(0) {
	
}

SimpleReg::~SimpleReg() {
	while (teamCount != 0) {
		removeTeam(head->t.name);
	}
	head = NULL;
}


void SimpleReg::addTeam(const string tName, const string tColor, const int tyear) {
	if (tyear < 1800 || tyear > 2020) {
		cout << "Invalid Year Entered" << endl;
		return;
	}
	if (findTeam(tName) == NULL) {
		Node* newPtr = new Node;
		Team* newT= new Team(tName, tColor,tyear);
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

void SimpleReg::removeTeam(const string teamName) {
	Node* ptr = findTeam(teamName);
	if (ptr == NULL) {
		cout << "Team Does Not Exist" << endl;
		return;
	}
	if (head == ptr) {
		head = ptr->next;
	}
	else{
		Node* prev = head;
		while (prev->next != ptr) {
			prev = prev->next;
		}
		prev->next = ptr->next;
	}
	delete ptr;
	teamCount--;
}

void SimpleReg::displayAllTeams() const {
	cout << endl;
	if (teamCount == 0) {
		cout << "---EMPTY---" << endl;
		return;
	}
	Node* cur = head;
	for (int i = 0; i < teamCount; i++) {
		cout << "Team: " << cur->t.name << " Color: " << cur->t.color << " Year: " << cur->t.year << endl;
		cur = cur->next;
	}
	cout << endl;
}


SimpleReg::Node* SimpleReg::findTeam(const string teamName) const {
	string str1;
	string str2 = teamName;

	Node* cur = head;
	for (int i = 0; i < teamCount; i++) {
		str1 = cur->t.name;
		for (int i = 0; i < str1.size(); i++)
		{
			str1[i] = tolower(str1[i]);
		}

		for (int i = 0; i < str2.size(); i++)
		{
			str2[i] = tolower(str2[i]);
		}

		if (str1 == str2) { //if true team exists
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}