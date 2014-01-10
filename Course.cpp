#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "Course.h"

ostream& operator<<(ostream& output, const Course& course)
{
	output << setw(16) << setfill(' ') << left << "Course Info:" << course.courseNumber << " -- " << course.courseName << endl
		   << setw(16) << left << "# of Units:" << course.courseUnits << endl
		   << setw(16) << left << "Course Dates:" << course.startDate << " - " << course.endDate << endl
		   << setw(16) << setfill(' ') << left << "Meeting Days:" << course.courseDays << endl
		   << setw(16) << setfill(' ') << left << "Meeting Time:" << course.startTime << " - " << course.endTime << endl
		   << setw(16) << setfill(' ') << left << "Daily Duration:" << course.calcDailyDuration() << " hours" << endl;
	return output;
}

Course::Course(const string& number , const string& name ,const string& days ,const double unitsC, const Date& startD, const Date& endD, const Time& startT, const Time& endT):
	courseNumber(number), courseName(name), courseDays(days), courseUnits(unitsC), startDate(startD), endDate(endD), startTime(startT), endTime(endT)
{
	cout << "constructorCOURSE" << endl;
}

Course::~Course()
{
	cout << "The course has been deleted.\n";
}

string Course::getNumber() const
{
	return courseNumber;
}

string Course::getName() const
{
	return courseName;
}

string Course::getDays() const
{
	return courseDays;
}

double Course::getUnits() const
{
	return courseUnits;
}

Time Course::getStartTime() const
{
	return startTime;
}

Time Course::getEndTime() const 
{
	return endTime;
}

Date Course::getStartDate() const
{
	return startDate;
}

Date Course::getEndDate() const
{
	return endDate;
}

Course& Course::setNumber(const string& x)
{
	courseNumber = x;
	return *this;
}

Course& Course::setName(const string& x)
{
	courseName = x;
	return *this;
}

Course& Course::setDays(const string& x)
{
	courseDays = x;
	return *this;
}

Course& Course::setUnits(const double x)
{
	courseUnits = x;
	return *this;
}

double Course::calcDailyDuration() const
{
	double x;
	x = getStartTime() - getEndTime();
	return x;
}
