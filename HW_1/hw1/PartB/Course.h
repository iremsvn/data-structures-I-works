#pragma once
#ifndef __COURSE_B_H
#define ___COURSE_B_H
#include <string>
using namespace std;

class Course {

public:
	Course();
	~Course();

private:
	int id;
	string name;

	friend class Student;

};
#endif