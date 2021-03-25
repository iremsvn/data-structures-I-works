
#ifndef __STUDENT_A_H
#define ___STUDENT_A_H
#include <string>
using namespace std;

class Student {
public:
	 Student();
	~Student();

private:
	int studentId;
	string firstName;
	string lastName;

	friend class RegistrationSystem;
};
#endif