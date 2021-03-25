#pragma once
#ifndef __REGISTRATION_SYSTEM_B_H
#define ___REGISTRATION_SYSTEM_B_H
using namespace std;
#include "Student.h"
#include "Course.h"

class RegistrationSystem {
public:
	RegistrationSystem();
	~RegistrationSystem();

	void addStudent(const int studentId, const string firstName, const string lastName);
	void deleteStudent(const int studentId);
	void addCourse(const int studentId, const int courseId, const string courseName);
	void withdrawCourse(const int studentId, const int courseId);
	void cancelCourse(const int courseId);
	void showStudent(const int studentId);
	void showCourse(const int courseId);
	void showAllStudents();

public:
	Student* students;
	int studentNumber;
};

#endif