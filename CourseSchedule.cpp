#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "CourseSchedule.h"

ostream& operator<<(ostream& output, const CourseSchedule& schedule)
{
	output << "\n\nCLASS SCHEDULE\n"
		   << "------------------------------------------\n"
		   << "Name: " << schedule.getStudentName() << endl
		   << "Number of Classes: " << schedule.numCourses << endl
		   << "------------------------------------------\n";
	for (int count = 0; count < schedule.numCourses; count++)
	{
		cout << schedule.coursePtr[count] << "\n\n";
	}
		   
	return output;
}

CourseSchedule::CourseSchedule(const string& studentName, const Semester& s, int maxSize): coursePtr(nullptr), studentName(studentName), semester(s)
	,maxSize(maxSize), numCourses(0)
{
	coursePtr = new Course [maxSize];
}

CourseSchedule::CourseSchedule(const CourseSchedule&): coursePtr(nullptr), studentName(" ")
	,maxSize(0), numCourses(0)
{
}

void CourseSchedule::operator=(const CourseSchedule&) const
{
}

CourseSchedule::~CourseSchedule()
{
	delete [] coursePtr;
	coursePtr = nullptr;
}

string CourseSchedule::getStudentName() const
{
	return studentName;
}


Semester CourseSchedule::getSemester() const
{
	return semester;
}


void CourseSchedule::setStudentName(string studentName)
{
	this->studentName = studentName;
}

int CourseSchedule::getNumCourses() const
{
	return numCourses;
}


bool CourseSchedule::checkDates(const Semester& s, const Date& startDate, const Date& endDate) const
{
	if(s.getStartDate() > startDate )
	{
		return false;
	}
	else if (s.getEndDate() < endDate )
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool CourseSchedule::addCourse(const Course& course)
{
	if (numCourses < maxSize)
	{
		if (checkDates( semester, course.getStartDate(), course.getEndDate() ))
		{
			for (int count = 0; count < numCourses; count++)
			{
				if (coursePtr[count].getNumber() == course.getNumber() &&
					coursePtr[count].getName() == course.getName())
				{
					return false; // if the course is already on the schedule, return false so it can't add the same course more than once.
				}
			}
			coursePtr[numCourses] = course;
			numCourses++;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
}


bool CourseSchedule::removeCourse(const Course& course)
{
	if(numCourses > 0)
	{
		int index = -1;	
		for (int count = 0; count < numCourses; count++)
		{
			if (coursePtr[count].getNumber() == course.getNumber() && 
				coursePtr[count].getName() == course.getName())
			{
				index = count;
			}
		}
		if (index != -1)
		{
			coursePtr[index] = coursePtr[numCourses-1];
			numCourses--;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
