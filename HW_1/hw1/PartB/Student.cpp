#include <iostream>
#include "Student.h"

Student::Student()
	:studentId(0), firstName(""), lastName(""), courseNumber(0), courses(NULL) {
}


Student::~Student() {
	delete[]courses;
}

bool Student::addCourse(int courseId, string courseName) {

	for (int i = 0; i < courseNumber; i++) {
		if (courses[i].id == courseId) {
			cout << "Student " << studentId << " already enrolled in course " << courseId << endl;
			return false;
		}
	}

	Course* temp = new Course[courseNumber + 1];
	for (int i = 0; i < courseNumber; i++) {
		temp[i] = courses[i];
	}
	temp[courseNumber].id = courseId;
	temp[courseNumber].name = courseName;
	delete[] courses;
	courses = temp;
	temp = NULL;
	courseNumber++;
	return true;
}

void Student::displayCourses() {
	if (courseNumber == 0) {
		return;
	}
	cout << "\tCourse id\tCourse name" << endl;
	for (int i = 0; i < courseNumber; i++) {
		cout << "\t" << courses[i].id << "\t\t" << courses[i].name << endl;
	}
}


bool Student::displayCourse(int courseId, bool display) {

	if (courseNumber == 0 || courses == NULL) {
		return false;
	}

	for (int i = 0; i < courseNumber; i++) {
		if (courseId == courses[i].id) {
			if (display == true) {
				cout << "\nCourse id\tCourse name" << endl;
				cout << courses[i].id << "\t\t" << courses[i].name << endl;
			}
			return true;
		}
	}
	return false;
}


bool Student::deleteCourse(int courseId) {
	int index = 0;
	for (; index < courseNumber; index++) {
		if (courseId == courses[index].id) {
			break;
		}
	}
	if (index == courseNumber) //it means course not exist for that student
		return false;
	Course* temp = new Course[courseNumber - 1];
	for (int i = 0; i < index; i++) {
		temp[i] = courses[i];
	}
	for (int i = index; i < courseNumber - 1; i++) {
		temp[i] = courses[i + 1];
	}
	delete[]courses;
	courses = temp;
	temp = NULL;
	courseNumber--;
	return true;
}


Student& Student::operator=(const Student& right) {
	if (&right != this)
	{
		studentId = right.studentId;
		firstName = right.firstName;
		lastName = right.lastName;
		if (courseNumber != right.courseNumber) {
			if (courseNumber > 0)
				delete[]courses;
			courseNumber = right.courseNumber;
			if (courseNumber > 0)
				courses = new Course[courseNumber];
			else
				courses = NULL;
		}
		for (int i = 0; i < courseNumber; i++)
			courses[i] = right.courses[i];
	}
	return *this;
}