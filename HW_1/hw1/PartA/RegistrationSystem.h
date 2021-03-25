
#ifndef __REGISTRATION_SYSTEM_A_H
#define ___REGISTRATION_SYSTEM_A_H
using namespace std;
#include "Student.h"

class RegistrationSystem {
public:
	RegistrationSystem();
	~RegistrationSystem();

	void addStudent(const int studentId, const string firstName, const string lastName);
	void deleteStudent(const int studentId);

	void showStudent(const int studentId);
	void showAllStudents();
public:
	Student* students;
	int studentNumber;

};

#endif