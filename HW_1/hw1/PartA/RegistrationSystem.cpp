#include <iostream>
#include "RegistrationSystem.h"


RegistrationSystem::RegistrationSystem():students(NULL),studentNumber(0) {
	
}

RegistrationSystem::~RegistrationSystem() {
		delete[] students;
}

void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {
	if (studentId <= 0 || firstName == "" || lastName == "") {
		cout << "invalid student information, check id or name fields" << endl;
		return;
	}

	int index = 0;
	for (; index < studentNumber; index++) {
		if (studentId == students[index].studentId) {
			cout << "Student " << studentId << " already exists" << endl;
			return;
		}
		if (studentId < students[index].studentId) {
			break;
		}
	}
	Student* temp = new Student[studentNumber + 1];
	for (int i = 0; i < index; i++) {
		temp[i] = students[i];
	}
	temp[index].studentId = studentId;
	temp[index].firstName = firstName;
	temp[index].lastName = lastName;
	for (int i = index; i < studentNumber; i++) {
		temp[i + 1] = students[i];
	}
	delete[] students;
	studentNumber++;
	students = temp;
	temp = NULL;
	cout << "Student " << studentId << " has been added" << endl;
}


void RegistrationSystem::deleteStudent(const int studentId) {
	if (studentId <= 0 || students == NULL || studentNumber <= 0) {
		if (studentId <= 0)
			cout << "invalid student id" << endl;
		else
			cout << "There are no students in the system" << endl;
		return;
	}
	int index = 0;
	for (; index < studentNumber; index++) {
		if (students[index].studentId == studentId) {
			break;
		}
	}
	if (index == studentNumber) { //it means id not exist
		cout << "Student " << studentId << " does not exist" << endl;
		return;
	}
	else
	{
		Student* temp = new Student[studentNumber - 1];
		for (int i = 0; i < index; i++) {
			temp[i] = students[i];
		}
		for (int i = index; i < studentNumber - 1; i++) {
			temp[i] = students[i + 1];
		}
		delete[] students;
		studentNumber--;
		if (studentNumber == 0)
			temp = NULL;
		students = temp;
		temp = NULL;
		cout << "Student " << studentId << " has been deleted" << endl;
	}
}


void RegistrationSystem::showAllStudents() {
	if (students == NULL || studentNumber == 0) {
		cout << "There are no students in the system" << endl;
		return;
	}
	cout << "\nStudent id\t" << "Fist Name\t" << "Last Name" << endl;
	for (int i = 0; i < studentNumber; i++) {
		cout << students[i].studentId << "\t\t" 
			<< students[i].firstName << "\t\t" << students[i].lastName << endl;
	}
	cout << endl;
}

void RegistrationSystem::showStudent(const int studentId) {
	for (int i = 0; i < studentNumber; i++) {
		if (studentId == students[i].studentId) {
			cout << students[i].studentId << "\t\t" << students[i].firstName << "\t\t" << students[i].lastName << endl;
			return;
		}
	}
	cout << "Student " << studentId << " does not exist" << endl;
}