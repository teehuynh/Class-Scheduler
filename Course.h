#ifndef COURSE_H
#define COURSE_H

#include "Date.h"
#include "Time.h"

class Course
{
	friend ostream& operator<<(ostream&, const Course&);

	private:
		string courseNumber;
		string courseName;
		string courseDays;
		double courseUnits;
		Date startDate;
		Date endDate;
		Time startTime;
		Time endTime;

	public:
		Course(const string& = "NULL", const string& = "NULL", const string& = "NULL", 
		const double = 0, const Date& = Date(),const Date& = Date(),const Time& = Time(),
		const Time& = Time());
		
		~Course();
		string getNumber() const;
		string getName() const;
		string getDays() const;
		double getUnits() const;
		Time getStartTime() const;
		Time getEndTime() const;
		Date getStartDate() const; 
		Date getEndDate() const;   
		Course& setNumber(const string&);
		Course& setName(const string&);
		Course& setDays(const string&);
		Course& setUnits(const double);
		double calcDailyDuration() const;
};

#endif
