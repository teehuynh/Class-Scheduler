#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "Semester.h"

ostream &operator<<(ostream& output, const Semester& sem) {
	output << "  " << sem.name << "  "
		   << " (" << sem.startDate << "-" << sem.endDate << ")";
	return output;
}

istream &operator>>(istream& input, Semester& sem) {
	input >> sem.name;
	input.ignore(2); //ignores " ("
	input >> sem.startDate;
	input.ignore(); //ignores "-"
	input >> sem.endDate;
	return input;
}

Semester::Semester(const string& nm, const Date& start, const Date& end): name(nm), startDate(start), endDate(end)
{
}

Semester& Semester::setName(string nm) {
	name = nm;
	return *this;
}

string Semester::getName()const {
	return name;
}

Semester& Semester::setStartDate(int month, int day, int year) {
	startDate.setMonth(month);
	startDate.setDay(day);
	startDate.setYear(year);
	return *this;
}

Semester& Semester::setEndDate(int month, int day, int year) {
	endDate.setMonth(month);
	endDate.setDay(day);
	endDate.setYear(year);
	return *this;
}

Date Semester::getStartDate()const {
	return startDate;
}

Date Semester::getEndDate()const {
	return endDate;
}