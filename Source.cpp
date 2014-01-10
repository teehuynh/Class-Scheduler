#include <iostream>
#include <string>

using namespace std;

#include "CourseSchedule.h"


int main() {
	Date startDate;
	Date endDate;
	int maxClass;
	string userName, semesterName;
	char selection;

	cout << "Enter your name: ";
	getline(cin,userName);
	cout << "Enter semester name: ";
	getline(cin,semesterName);
	cout << "Enter the start date (month#/day#/year#): ";
	cin >> startDate;
	cout << "Enter the end date (month#/day#/year#): ";
	cin >> endDate;
	cout << "Enter maximum number of classes: ";
	cin >> maxClass;
	
	Semester semester(semesterName, startDate, endDate);
	CourseSchedule courseSched(userName, semester, maxClass);

	do {
		cout << "COURSE ENTRY MENU FOR: " << semester << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "1) Enter a new course" << endl;
		cout << "2) Remove a course" << endl;
		cout << "3) Print a Semester Schedule" << endl;
		cout << "q) Quit the program" << endl;
		cin >> selection;
		cin.ignore();

		switch (selection) {

				case '1':
				{
					Time startTime;
					Time endTime;
					Date start;
					Date end;
					double courseUnits;
					string courseName, courseNum, meetDays;

					if (courseSched.getNumCourses() == maxClass)
					{
						cout << "\nYour schedule is full. Please remove a class to add another.\n";
						break;
					}

					cout << "Enter course number: ";
					getline(cin, courseNum);
					cout << "Enter course name: ";
					getline(cin, courseName);
					cout << "Number of units for course: ";
					cin >> courseUnits;
					cin.ignore();
					cout << "Enter meeting days: ";
					getline(cin, meetDays);
					cout << "Enter the starting time (hour#:minute# AM/PM): ";
					cin >> startTime;
					cout << "Enter the ending time (hour#:minute# AM/PM): ";
					cin >> endTime;
					cout << "Enter the start date (month#/day#/year#): ";
					cin >> start;
					cout << "Enter the end date (month#/day#/year#): ";
					cin >> end;

					Course course(courseNum, courseName, meetDays, courseUnits, start, end, startTime, endTime);

					if (courseSched.addCourse(course)) 
					{
						cout << "Course successfully added!" << endl;
					}
					else 
					{
						cout << "Error: INVALID INPUT" << endl;
					}
					break;
				}
				case '2':
				{
					Time startTime;
					Time endTime;
					Date start;
					Date end;
					double courseUnits;
					string courseName, courseNum, meetDays;

					if (courseSched.getNumCourses() == 0)
					{
						cout << "\nYou do not have any courses to remove.\n";
						break;
					}
					cout << "Enter course number: ";
					getline(cin, courseNum);
					cout << "Enter course name: ";
					getline(cin, courseName);
					
					Course course(courseNum, courseName);

					if (courseSched.removeCourse(course)) {
						cout << "Course successfully removed!" << endl;
					}
					else {
						cout << "Error: INVALID INPUT" << endl;
					}
					break;
				}
				case '3':
				{
					cout << courseSched;
					break;
				}
				case 'Q':
				case 'q':
				{
					cout << "Have a good day!" << endl;
					break;
				}
				default:
					cout << "Invalid choice. Please try again." << endl;
					break;
		}
	} while (toupper(selection) != ('Q'));

	system("pause");
	return 0;
}