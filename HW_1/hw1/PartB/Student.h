#pragma once
#ifndef __STUDENT_B_H
#define ___STUDENT_B_H
#include <string>
#include "Course.h"
using namespace std;

class Student {
public:
	Student();
	~Student();
	bool addCourse(int courseId, string courseName);  //returns true if addition was successful
	void displayCourses(); //displays all courses for that student
	bool displayCourse(int courseId, bool display = true);  //if display = false it only returns whether course exists or not
	bool deleteCourse(int courseId); //returns true if deletion was successful

	Student& operator=(const Student&); //used for deep copying the courses

private:
	int studentId;
	string firstName;
	string lastName;

	Course* courses; //array of courses
	int courseNumber; //courses array lenght

	friend class RegistrationSystem; 
};
#endif
