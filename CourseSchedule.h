#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
#include "Date.h"
#include "Time.h"
#include "Course.h"
#include "Semester.h"

using namespace std;

class CourseSchedule
{
	friend ostream& operator<<(ostream&, const CourseSchedule&);

	private:
		string studentName;
		Semester semester;
		int maxSize; //maximum number of courses that can be added to a schedule
		Course* coursePtr;
		int numCourses;	// number of courses added
		bool checkDates(const Semester&, const Date&, const Date&) const;

	public:
		CourseSchedule(const string& = "Student Name", const Semester& = Semester(), int = 0); 
		CourseSchedule(const CourseSchedule&);
		~CourseSchedule();
		void operator=(const CourseSchedule&) const;
		string getStudentName() const;	
		Semester getSemester() const;
		int getNumCourses() const;
		void setStudentName(string);
		bool addCourse(const Course&); //returns true if it added the course
		bool removeCourse(const Course&); //returns true if it removed the course
};

#endif
