#ifndef SEMESTER_H
#define SEMESTER_H

#include "Course.h"
#include "Date.h"
#include "Time.h"


class Semester {

	friend ostream &operator<<(ostream&, const Semester&);
	friend istream &operator>>(istream&, Semester&);

	private:
		string name;
		Date startDate;
		Date endDate;

	public:
		Semester(const string& = "NULL" , const Date& = Date(), const Date& = Date()); 
		Semester& setName(string);
		string getName()const;
		Semester& setStartDate(int, int, int);
		Semester& setEndDate(int, int, int);
		Date getStartDate()const;
		Date getEndDate()const;
};
#endif