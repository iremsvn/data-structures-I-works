#include <iostream>
#include "RegistrationSystem.h"


RegistrationSystem::RegistrationSystem() :students(NULL), studentNumber(0) {

}

RegistrationSystem::~RegistrationSystem() {
	delete[]students;
}

void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {
	if (studentId <= 0 || firstName == "" || lastName == "") {
		cout << "invalid information: check id and name fields" << endl;
		return;
	}

	int index = 0;
	for (; index < studentNumber; index++) {
		if (studentId == students[index].studentId) {
			cout << "Student " << studentId << " already exist" << endl;
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
	students = temp;
	temp = NULL;
	studentNumber++;
	cout << "Student " << studentId << " has been added" << endl;

}

void RegistrationSystem::deleteStudent(const int studentId) {
	if (studentId <= 0 || studentNumber == 0 || students == NULL){
		if (studentId <= 0)
			cout << "invalid student id " << endl;
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
		if(studentNumber == 0)
			temp = NULL;
		students = temp;
		cout << "Student " << studentId << " has been deleted" << endl;
	}
}


void RegistrationSystem::showAllStudents() {
	if (studentNumber == 0) {
		cout << "There are no students in the system." << endl;
		return;
	}
	cout << "\nStudent id\tFirst name\tLastName" << endl;
	for (int i = 0; i < studentNumber; i++) {
		cout << students[i].studentId << "\t\t"
			<< students[i].firstName << "\t\t" << students[i].lastName << endl;
		students[i].displayCourses();
	}
	cout << endl;
}

void RegistrationSystem::showStudent(const int studentId) {
	for (int i = 0; i < studentNumber; i++) {
		if (studentId == students[i].studentId) {
			cout << "\nStudent id\tFirst name\tLast name" << endl;
			cout << students[i].studentId << "\t\t" << students[i].firstName << "\t\t" << students[i].lastName << endl;
			students[i].displayCourses();
			return;
		}
	}
	cout << "Student " << studentId << " does not exist" << endl;
}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName) {
	if (studentNumber == 0) {
		cout << "There are no students in the system" << endl;
		return;
	}
	for (int i = 0; i < studentNumber; i++) {
		if (studentId == students[i].studentId) {
			if(students[i].addCourse(courseId, courseName))
			cout << "Course " << courseId << " has been added for student " << studentId << endl; 
			return;
		}
	}
	cout << "Student " << studentId << " does not exist" << endl;
}


void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
	if (studentNumber == 0) {
		cout << "There are no students in the system" << endl;
		return;
	}

	for (int i = 0; i < studentNumber; i++) {
		if (studentId == students[i].studentId) {
			if(students[i].deleteCourse(courseId))
			    cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
			else
				cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
			return;
		}
	}
	cout << "Student " << studentId << " does not exist" << endl;
}


void RegistrationSystem::cancelCourse(const int courseId) {
	if (studentNumber == 0) {
		cout << "There are no students in the system" << endl;
		return;
	}
	int count = 0;
	for (int i = 0; i < studentNumber; i++) {
		if (students[i].deleteCourse(courseId)){
			count++;
		}
	}
	if (count == 0) 
		cout << "Course " << courseId << " does not exist" << endl;
	else
		cout << "Course " << courseId << " has been deleted." << endl;
}


void RegistrationSystem::showCourse(const int courseId) {
	if (studentNumber == 0) {
		cout << "There are no students in the system" << endl;
		return;
	}
	int count = 0;
	for (int i = 0; i < studentNumber; i++) {
		if (students[i].displayCourse(courseId, false)) //it will only return whether course exist or not
		{
			count++;
			if (count == 1) {
				students[i].displayCourse(courseId);
				cout << "\tStudent id\tFirst name\tLast Name" << endl;
			}
			cout << "\t" << students[i].studentId << "\t\t" << students[i].firstName << "\t\t" << students[i].lastName << endl;
		}
	}

	if (count == 0)
		cout << "Course " << courseId << " does not exist." << endl;
}

